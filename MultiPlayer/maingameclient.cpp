/**
 * @file maingameclient.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of maingameclient.h.
 * @version 1.0
 * @date 2021-09-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "maingameclient.h"

MainGameClient::MainGameClient(QWidget *parent) {
    // Empty on purpose
}

MainGameClient::~MainGameClient() {
    // Empty on purpose
}

void MainGameClient::connectToServer(std::string _serverIPAddress) {
    serverIPAddress = _serverIPAddress;

    // WSA Initialization
    result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        // Ignore
    }

    // Create TCP socket
    if ((mainSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        WSACleanup();
    }

    // Create adress
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(g_PORT);
    srv_addr.sin_addr.s_addr = inet_addr(serverIPAddress.c_str());
    memset(&(srv_addr.sin_zero), '\0', sizeof(srv_addr.sin_zero));

    // Connect
    if (::connect(mainSocket, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) ==
        SOCKET_ERROR) {
        WSACleanup();
    }
}

void MainGameClient::startSending() {
    connect(game->getTimerGame(), SIGNAL(timeout()), this,
            SLOT(sendToServer()));
}

void MainGameClient::prepareMessage() {
    memset(&sendBuff, '\0', g_BUFFSIZE);

    // 0 - mainGame / 1 - secondGame
    sendBuff[0] = '0';

    // Main game pause
    sendBuff[1] = ((int)game->getIsGamePaused()) + '0';

    // Red ghost position
    sendBuff[2] = (((game->getRedGhostPositionX()) -
                    ((game->getRedGhostPositionX()) % 10)) /
                   10) +
                  '0';
    sendBuff[3] = ((game->getRedGhostPositionX()) % 10) + '0';
    sendBuff[4] = (((game->getRedGhostPositionY()) -
                    ((game->getRedGhostPositionY()) % 10)) /
                   10) +
                  '0';
    sendBuff[5] = ((game->getRedGhostPositionY()) % 10) + '0';

    // Orange ghost position
    sendBuff[6] = (((game->getOrangeGhostPositionX()) -
                    ((game->getOrangeGhostPositionX()) % 10)) /
                   10) +
                  '0';
    sendBuff[7] = ((game->getOrangeGhostPositionX()) % 10) + '0';
    sendBuff[8] = (((game->getOrangeGhostPositionY()) -
                    ((game->getOrangeGhostPositionY()) % 10)) /
                   10) +
                  '0';
    sendBuff[9] = ((game->getOrangeGhostPositionY()) % 10) + '0';

    // Blue ghost position
    sendBuff[10] = (((game->getBlueGhostPositionX()) -
                     ((game->getBlueGhostPositionX()) % 10)) /
                    10) +
                   '0';
    sendBuff[11] = ((game->getBlueGhostPositionX()) % 10) + '0';
    sendBuff[12] = (((game->getBlueGhostPositionY()) -
                     ((game->getBlueGhostPositionY()) % 10)) /
                    10) +
                   '0';
    sendBuff[13] = ((game->getBlueGhostPositionY()) % 10) + '0';

    // Pink ghost position
    sendBuff[14] = (((game->getPinkGhostPositionX()) -
                     ((game->getPinkGhostPositionX()) % 10)) /
                    10) +
                   '0';
    sendBuff[15] = ((game->getPinkGhostPositionX()) % 10) + '0';
    sendBuff[16] = (((game->getPinkGhostPositionY()) -
                     ((game->getPinkGhostPositionY()) % 10)) /
                    10) +
                   '0';
    sendBuff[17] = ((game->getPinkGhostPositionY()) % 10) + '0';

    // Main game pacman position
    sendBuff[18] =
        (((game->getPacmanPositionX()) - ((game->getPacmanPositionX()) % 10)) /
         10) +
        '0';
    sendBuff[19] = ((game->getPacmanPositionX()) % 10) + '0';
    sendBuff[20] =
        (((game->getPacmanPositionY()) - ((game->getPacmanPositionY()) % 10)) /
         10) +
        '0';
    sendBuff[21] = ((game->getPacmanPositionY()) % 10) + '0';

    // Score points
    int scorePoints = game->getScorePoints();
    sendBuff[24] = (scorePoints % 10) + '0';
    scorePoints /= 10;
    sendBuff[23] = (scorePoints % 10) + '0';
    scorePoints /= 10;
    sendBuff[22] = (scorePoints % 10) + '0';

    // Game end lose
    sendBuff[25] = ((int)game->getGameLoseClose()) + '0';
}

void MainGameClient::sendToServer() {
    reciveFromServer();

    prepareMessage();

    // Send data
    if (send(mainSocket, sendBuff, strlen(sendBuff), 0) == SOCKET_ERROR) {
        WSACleanup();
    }
}

void MainGameClient::reciveFromServer() {
    // Check is there anything to receive
    unsigned long howManyToRecv;
    ioctlsocket(mainSocket, FIONREAD, &howManyToRecv);
    if (howManyToRecv > 0) {
        recv(mainSocket, recvBuff, g_BUFFSIZE, 0);

        // Pause
        if (recvBuff[0] == '1') {
            game->setIsGamePaused(!game->getIsGamePaused());
        }
        // Other pacman position
        game->setOtherPacmanPositionX(
            (((recvBuff[1] - '0') * 10) + (recvBuff[2] - '0')));
        game->setOtherPacmanPositionY(
            (((recvBuff[3] - '0') * 10) + (recvBuff[4] - '0')));

        // Score points
        int receivedScorePoints = ((recvBuff[5] - '0') * 100) +
                                  ((recvBuff[6] - '0') * 10) +
                                  (recvBuff[7] - '0');
        game->setScorePointsReceivedFromServer(receivedScorePoints);

        // Game end lose
        if (recvBuff[8] == '1') {
            game->closeGame();
        }

        // Pacman eaten but not dead in second game
        if (recvBuff[9] == '1') {
            game->pacmanEatenInSecondGame();
        }

        // Ghost eaten in second game
        if (recvBuff[10] == '1') {
            int eatenGhostX =
                ((recvBuff[11] - '0') * 10) + (recvBuff[12] - '0');
            int eatenGhostY =
                ((recvBuff[13] - '0') * 10) + (recvBuff[14] - '0');
            game->ghostEatenInSecondGame(eatenGhostX, eatenGhostY);
        }
    }
}
