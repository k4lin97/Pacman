/**
 * @file secondgameclient.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of secondgameclient.h.
 * @version 1.0
 * @date 2021-09-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "secondgameclient.h"

SecondGameClient::SecondGameClient(QWidget *parent) {
    // Empty on puropose
}

SecondGameClient::~SecondGameClient() {
    // Empty on puropose
}

void SecondGameClient::connectToServer(std::string _serverIPAddress) {
    serverIPAddress = _serverIPAddress;

    // WSA initialization
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

void SecondGameClient::startSending() {
    connect(game->getTimerGame(), SIGNAL(timeout()), this,
            SLOT(sendToServer()));
}

void SecondGameClient::prepareMessage() {
    memset(&sendBuff, '\0', g_BUFFSIZE);

    // 0 - mainGame / 1 - secondGame
    sendBuff[0] = '1';

    // Second game pause
    sendBuff[1] = ((int)game->getIsGamePaused()) + '0';

    // Second game pacman
    sendBuff[2] =
        (((game->getPacmanPositionX()) - ((game->getPacmanPositionX()) % 10)) /
         10) +
        '0';
    sendBuff[3] = ((game->getPacmanPositionX()) % 10) + '0';
    sendBuff[4] =
        (((game->getPacmanPositionY()) - ((game->getPacmanPositionY()) % 10)) /
         10) +
        '0';
    sendBuff[5] = ((game->getPacmanPositionY()) % 10) + '0';

    // Score points
    int scorePoints = game->getScorePoints();
    sendBuff[8] = (scorePoints % 10) + '0';
    scorePoints /= 10;
    sendBuff[7] = (scorePoints % 10) + '0';
    scorePoints /= 10;
    sendBuff[6] = (scorePoints % 10) + '0';

    // Game end lose
    sendBuff[9] = ((int)game->getGameLoseClose()) + '0';

    // Pacman eaten but not dead
    sendBuff[10] = ((int)game->getPacmanEatenButNotDeadBool()) + '0';
    game->setPacmanEatenButNotDeadBool(false);

    // Pacman eats ghost
    sendBuff[11] = ((int)game->getGhostEaten()) + '0';
    game->setGhostEaten(false);

    int ghostX = game->getEatenGhostX();
    sendBuff[13] = (ghostX % 10) + '0';
    ghostX /= 10;
    sendBuff[12] = (ghostX % 10) + '0';

    int ghostY = game->getEatenGhostY();
    sendBuff[15] = (ghostY % 10) + '0';
    ghostY /= 10;
    sendBuff[14] = (ghostY % 10) + '0';
}

void SecondGameClient::sendToServer() {
    reciveFromServer();

    prepareMessage();

    if (send(mainSocket, sendBuff, strlen(sendBuff), 0) == SOCKET_ERROR) {
        WSACleanup();
    }
}

void SecondGameClient::reciveFromServer() {
    unsigned long howManyToRecv;
    ioctlsocket(mainSocket, FIONREAD, &howManyToRecv);

    if (howManyToRecv > 0) {
        recv(mainSocket, recvBuff, g_BUFFSIZE, 0);

        // Pause
        if (recvBuff[0] == '1') {
            game->setIsGamePaused(!game->getIsGamePaused());
        }
        // Red Ghost
        game->setRedGhostPositionX(
            (((recvBuff[1] - '0') * 10) + (recvBuff[2] - '0')));
        game->setRedGhostPositionY(
            (((recvBuff[3] - '0') * 10) + (recvBuff[4] - '0')));

        // Orange Ghost
        game->setOrangeGhostPositionX(
            (((recvBuff[5] - '0') * 10) + (recvBuff[6] - '0')));
        game->setOrangeGhostPositionY(
            (((recvBuff[7] - '0') * 10) + (recvBuff[8] - '0')));

        // Blue Ghost
        game->setBlueGhostPositionX(
            (((recvBuff[9] - '0') * 10) + (recvBuff[10] - '0')));
        game->setBlueGhostPositionY(
            (((recvBuff[11] - '0') * 10) + (recvBuff[12] - '0')));

        // Pink Ghost
        game->setPinkGhostPositionX(
            (((recvBuff[13] - '0') * 10) + (recvBuff[14] - '0')));
        game->setPinkGhostPositionY(
            (((recvBuff[15] - '0') * 10) + (recvBuff[16] - '0')));

        // Other Pacman
        game->setOtherPacmanPositionX(
            (((recvBuff[17] - '0') * 10) + (recvBuff[18] - '0')));
        game->setOtherPacmanPositionY(
            (((recvBuff[19] - '0') * 10) + (recvBuff[20] - '0')));

        // Score Points
        int receivedScorePoints = ((recvBuff[21] - '0') * 100) +
                                  ((recvBuff[22] - '0') * 10) +
                                  (recvBuff[23] - '0');
        game->setScorePointsReceivedFromServer(receivedScorePoints);

        // Game End Lose
        if (recvBuff[24] == '1') {
            game->closeGame();
        }
    }
}
