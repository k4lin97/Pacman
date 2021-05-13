#include "client.h"

#include <QDebug>

Client::Client(MainGameManager *_mainGame, SecondGameManager *_secondGame)
{
    mainGame = _mainGame;
    secondGame = _secondGame;

    /*if (connectToServer() == 0) {
        qDebug() << "Connected to server";
    } else {
        qDebug() << "Connection failed";
    }*/

    //int k = sendToServer();


}

Client::~Client()
{
    delete mainGame;
    delete secondGame;

    closesocket(mainSocket);
    WSACleanup();
}

void Client::startSending()
{
    connect(mainGame->getTimer_game(), SIGNAL(timeout()), this, SLOT(sendToServer()));
}

void Client::prepareMessage()
{
    /*stringMessage = gameManager->getIsGamePaused() ? "1" : "0";
    stringMessage.append(BREAK_DATA);
    stringMessage.append(BREAK_MESSAGE);
    stringMessage.append(secondGame->getIsGamePaused() ? "1" : "0");
    stringMessage.append(BREAK_DATA);

    memcpy(sendBuff, stringMessage.c_str(), stringMessage.size());*/

    // Main Game Pause
    //int sign = (int)mainGame->getIsGamePaused();
    sendBuff[0] = ((int)mainGame->getIsGamePaused()) + '0';
    sendBuff[1] = '$';

    // Red Ghost
    sendBuff[2] = (((mainGame->getRedGhostPositionX()) - ((mainGame->getRedGhostPositionX()) % 10)) / 10) + '0';
    sendBuff[3] = ((mainGame->getRedGhostPositionX()) % 10) + '0';
    sendBuff[4] = (((mainGame->getRedGhostPositionY()) - ((mainGame->getRedGhostPositionY()) % 10)) / 10) + '0';
    sendBuff[5] = ((mainGame->getRedGhostPositionY()) % 10) + '0';

    // Orange Ghost
    sendBuff[6] = (((mainGame->getOrangeGhostPositionX()) - ((mainGame->getOrangeGhostPositionX()) % 10)) / 10) + '0';
    sendBuff[7] = ((mainGame->getOrangeGhostPositionX()) % 10) + '0';
    sendBuff[8] = (((mainGame->getOrangeGhostPositionY()) - ((mainGame->getOrangeGhostPositionY()) % 10)) / 10) + '0';
    sendBuff[9] = ((mainGame->getOrangeGhostPositionY()) % 10) + '0';

    // Blue Ghost
    sendBuff[10] = (((mainGame->getBlueGhostPositionX()) - ((mainGame->getBlueGhostPositionX()) % 10)) / 10) + '0';
    sendBuff[11] = ((mainGame->getBlueGhostPositionX()) % 10) + '0';
    sendBuff[12] = (((mainGame->getBlueGhostPositionY()) - ((mainGame->getBlueGhostPositionY()) % 10)) / 10) + '0';
    sendBuff[13] = ((mainGame->getBlueGhostPositionY()) % 10) + '0';

    // Pink Ghost
    sendBuff[14] = (((mainGame->getPinkGhostPositionX()) - ((mainGame->getPinkGhostPositionX()) % 10)) / 10) + '0';
    sendBuff[15] = ((mainGame->getPinkGhostPositionX()) % 10) + '0';
    sendBuff[16] = (((mainGame->getPinkGhostPositionY()) - ((mainGame->getPinkGhostPositionY()) % 10)) / 10) + '0';
    sendBuff[17] = ((mainGame->getPinkGhostPositionY()) % 10) + '0';
    sendBuff[18] = '$';

    // Main Game Pacman
    sendBuff[19] = (((mainGame->getPacmanPositionX()) - ((mainGame->getPacmanPositionX()) % 10)) / 10) + '0';
    sendBuff[20] = ((mainGame->getPacmanPositionX()) % 10) + '0';
    sendBuff[21] = (((mainGame->getPacmanPositionY()) - ((mainGame->getPacmanPositionY()) % 10)) / 10) + '0';
    sendBuff[22] = ((mainGame->getPacmanPositionY()) % 10) + '0';
    sendBuff[23] = '$';

    // Score Points
    sendBuff[24] = ((mainGame->getScorePoints() - (mainGame->getScorePoints() % 100)) / 100) + '0';
    sendBuff[25] = (((mainGame->getScorePoints() % 100) - (mainGame->getScorePoints() % 10)) / 10) + '0';
    sendBuff[26] = (mainGame->getScorePoints() % 10) + '0';
    sendBuff[27] = '$';

    // Game End Lose
    sendBuff[28] = (mainGame->getGameLoseClose()) + '0';
    sendBuff[29] = '$';

    // BREAK_MESSAGE
    sendBuff[30] = '#';

    // Second Game Pause
    //sign = (int)secondGame->getIsGamePaused();
    sendBuff[31] = ((int)secondGame->getIsGamePaused()) + '0';
    sendBuff[32] = '$';

    // Second Game Pacman
    sendBuff[33] = (((secondGame->getPacmanPositionX()) - ((secondGame->getPacmanPositionX()) % 10)) / 10) + '0';
    sendBuff[34] = ((secondGame->getPacmanPositionX()) % 10) + '0';
    sendBuff[35] = (((secondGame->getPacmanPositionY()) - ((secondGame->getPacmanPositionY()) % 10)) / 10) + '0';
    sendBuff[36] = ((secondGame->getPacmanPositionY()) % 10) + '0';
    sendBuff[37] = '$';

    // Score Points
    sendBuff[38] = ((secondGame->getScorePoints() - (secondGame->getScorePoints() % 100)) / 100) + '0';
    sendBuff[39] = (((secondGame->getScorePoints() % 100) - (secondGame->getScorePoints() % 10)) / 10) + '0';
    sendBuff[40] = (secondGame->getScorePoints() % 10) + '0';
    sendBuff[41] = '$';

    // Game End Lose
    sendBuff[42] = (secondGame->getGameLoseClose()) + '0';
    sendBuff[43] = '$';

    // End
    sendBuff[g_BUFFSIZE - 1] = '\0';
    qDebug() << "Prepared message: " << sendBuff;
}

/*
 * Returns 0 if succeeded or 1 if failed.
 * */
int Client::sendToServer()
{
    // Tutaj jest połączenie - można coś wysłać
    prepareMessage();

    // Jeżeli nie ma błędów send zwraca ilość wysłanych bajtów
    if (send(mainSocket, sendBuff, strlen(sendBuff), 0) == SOCKET_ERROR) {
        qDebug() << "Failed to send.";
        WSACleanup();
        return 1;
    }

    reciveFromServer();
    return 0;
}

void Client::reciveFromServer()
{
    int bytesRecv = SOCKET_ERROR;

    bytesRecv = recv(mainSocket, recvBuff, g_BUFFSIZE, 0);
    //qDebug() << "Odebralem bajtow: " << bytesRecv;
    qDebug() << "Recieved buffer: " << recvBuff;

    // Został zmieniony stan w mainGame dlatego zmieniamy w secondGame
    if (recvBuff[0] == '1') {
        //qDebug() << "Pausa dla secondGame";
        secondGame->setIsGamePaused(!secondGame->getIsGamePaused());
    }
    // Został zmieniony stan w secondGame dlatego zmieniamy w mainGame
    if (recvBuff[1] == '1') {
        //qDebug() << "Pausa dla mainGame";
        mainGame->setIsGamePaused(!mainGame->getIsGamePaused());
    }

    // Red Ghost
    secondGame->setRedGhostPositionX((((recvBuff[2] - '0') * 10) + (recvBuff[3] - '0')));
    secondGame->setRedGhostPositionY((((recvBuff[4] - '0') * 10) + (recvBuff[5] - '0')));

    // Orange Ghost
    secondGame->setOrangeGhostPositionX((((recvBuff[6] - '0') * 10) + (recvBuff[7] - '0')));
    secondGame->setOrangeGhostPositionY((((recvBuff[8] - '0') * 10) + (recvBuff[9] - '0')));

    // Blue Ghost
    secondGame->setBlueGhostPositionX((((recvBuff[10] - '0') * 10) + (recvBuff[11] - '0')));
    secondGame->setBlueGhostPositionY((((recvBuff[12] - '0') * 10) + (recvBuff[13] - '0')));

    // Pink Ghost
    secondGame->setPinkGhostPositionX((((recvBuff[14] - '0') * 10) + (recvBuff[15] - '0')));
    secondGame->setPinkGhostPositionY((((recvBuff[16] - '0') * 10) + (recvBuff[17] - '0')));

    // Other Pacmans
    secondGame->setOtherPacmanPositionX((((recvBuff[18] - '0') * 10) + (recvBuff[19] - '0')));
    secondGame->setOtherPacmanPositionY((((recvBuff[20] - '0') * 10) + (recvBuff[21] - '0')));

    mainGame->setOtherPacmanPositionX((((recvBuff[22] - '0') * 10) + (recvBuff[23] - '0')));
    mainGame->setOtherPacmanPositionY((((recvBuff[24] - '0') * 10) + (recvBuff[25] - '0')));

    // Score Points
    mainGame->setScorePoints((((recvBuff[26] - '0') * 100) + ((recvBuff[27] - '0') * 10) + (recvBuff[28] - '0')));
    secondGame->setScorePoints((((recvBuff[26] - '0') * 100) + ((recvBuff[27] - '0') * 10) + (recvBuff[28] - '0')));

    // Close Lose
    if (((recvBuff[29] - '0') == 1) || ((recvBuff[30] - '0') == 1)){
        secondGame->closeGame();
        mainGame->closeGame();
    }

    //qDebug() << "Main game score poinst: " << mainGame->getScorePoints() << " Second game score poinst: " << secondGame->getScorePoints();

    //qDebug() << "Received text: " << recvBuff[0] << " | " << recvBuff[1];
}
