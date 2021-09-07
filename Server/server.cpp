#include <winsock2.h>

#include <iostream>
#include <string>

#define g_PORT 27015
#define g_BUFFSIZE 256

#define map_height 31
#define map_width 28

char mainGamePaused;
char secondGamePaused;

int scorePoints;

char firstClientMessage[g_BUFFSIZE] = "";   // Message received on first socket
char secondClientMessage[g_BUFFSIZE] = "";  // Message received on second socket

char mainGameMessage[g_BUFFSIZE] = "";    // Message from main game
char secondGameMessage[g_BUFFSIZE] = "";  // Message from second game

char serverReplyToMainGame[g_BUFFSIZE] = "";
char serverReplyToSecondGame[g_BUFFSIZE] = "";

SOCKET mainSocket;  // Main socket
SOCKET mainGameAcceptSocket = SOCKET_ERROR;
SOCKET secondGameAcceptSocket = SOCKET_ERROR;

void sendToClient();

int main() {
    std::string serverIPAddress;
    std::cout << "Enter the IP address. For one machine 127.0.0.1" << std::endl;
    std::cin >> serverIPAddress;

    mainGamePaused = '1';  // 1 - true
    secondGamePaused = '1';

    scorePoints = 0;

    WSADATA wsaData;
    int result;

    // WSA initialization
    result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        std::cout << "Initialization error." << std::endl;
        return 1;
    }

    // Create TCP socket
    if ((mainSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        std::cout << "Error creating socket." << std::endl;
        WSACleanup();
        return 1;
    }

    // Create address
    sockaddr_in srv_addr;  // My address
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(g_PORT);
    srv_addr.sin_addr.s_addr = inet_addr(serverIPAddress.c_str());
    memset(&(srv_addr.sin_zero), '\0', sizeof(srv_addr.sin_zero));

    // Bind created socket
    if (bind(mainSocket, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) ==
        SOCKET_ERROR) {
        std::cout << "Error creating socket." << std::endl;
        closesocket(mainSocket);
        WSACleanup();
        return 1;
    }

    // Server can listen on mainSocket
    if (listen(mainSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cout << "Error listening on socket." << std::endl;
        WSACleanup();
        return 1;
    }

    std::cout << "Waiting for a client 1 to connect..." << std::endl;
    while (mainGameAcceptSocket == SOCKET_ERROR) {
        mainGameAcceptSocket = accept(mainSocket, NULL, NULL);
    }
    std::cout << "Client 1 connected." << std::endl;

    std::cout << "Waiting for a client 2 to connect..." << std::endl;
    while (secondGameAcceptSocket == SOCKET_ERROR) {
        secondGameAcceptSocket = accept(mainSocket, NULL, NULL);
    }
    std::cout << "Client 2 connected." << std::endl;

    int bytesReceivedFromMainGame = -1;
    int bytesReceivedFromSecondGame = -1;

    do {
        // Clear
        memset(&(firstClientMessage), '\0', sizeof(firstClientMessage));
        memset(&(secondClientMessage), '\0', sizeof(secondClientMessage));
        bytesReceivedFromMainGame =
            recv(mainGameAcceptSocket, firstClientMessage, g_BUFFSIZE, 0);
        bytesReceivedFromSecondGame =
            recv(secondGameAcceptSocket, secondClientMessage, g_BUFFSIZE, 0);
        sendToClient();
    } while ((bytesReceivedFromMainGame > 0) ||
             (bytesReceivedFromSecondGame > 0));

    closesocket(mainGameAcceptSocket);
    closesocket(secondGameAcceptSocket);
    closesocket(mainSocket);
    WSACleanup();
    system("pause");
    return 0;
}

void sendToClient() {
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Received from client main: " << firstClientMessage
              << std::endl;
    std::cout << "Received from client second: " << secondClientMessage
              << std::endl;

    memset(&(serverReplyToMainGame), '@', g_BUFFSIZE);
    memset(&(serverReplyToSecondGame), '@', g_BUFFSIZE);

    if (firstClientMessage[0] == '0') {
        memcpy(&(mainGameMessage), &(firstClientMessage), g_BUFFSIZE);
        memcpy(&(secondGameMessage), &(secondClientMessage), g_BUFFSIZE);
    } else {
        memcpy(&(mainGameMessage), &(secondClientMessage), g_BUFFSIZE);
        memcpy(&(secondGameMessage), &(firstClientMessage), g_BUFFSIZE);
    }

    // Game pause
    if (mainGameMessage[1] != mainGamePaused) {
        // There was a change in main
        mainGamePaused = mainGameMessage[1];
        secondGamePaused = mainGameMessage[1];
        serverReplyToSecondGame[0] = '1';
    } else if (secondGameMessage[1] != secondGamePaused) {
        // There was a change in second
        secondGamePaused = secondGameMessage[1];
        mainGamePaused = secondGameMessage[1];
        serverReplyToMainGame[0] = '1';
    }

    // Score points
    int mainGameScorePoints = ((mainGameMessage[22] - '0') * 100) +
                              ((mainGameMessage[23] - '0') * 10) +
                              (mainGameMessage[24] - '0');
    int secondGameScorePoints = ((secondGameMessage[6] - '0') * 100) +
                                ((secondGameMessage[7] - '0') * 10) +
                                (secondGameMessage[8] - '0');
    scorePoints = mainGameScorePoints + secondGameScorePoints;

    // Server reply to main game

    // Other pacman
    serverReplyToMainGame[1] = secondGameMessage[2];
    serverReplyToMainGame[2] = secondGameMessage[3];
    serverReplyToMainGame[3] = secondGameMessage[4];
    serverReplyToMainGame[4] = secondGameMessage[5];

    serverReplyToMainGame[5] =
        ((scorePoints - (scorePoints % 100)) / 100) + '0';
    serverReplyToMainGame[6] =
        (((scorePoints % 100) - (scorePoints % 10)) / 10) + '0';
    serverReplyToMainGame[7] = (scorePoints % 10) + '0';

    // Game End Lose
    serverReplyToMainGame[8] = secondGameMessage[9];

    // Pacman eaten but not dead in second game
    serverReplyToMainGame[9] = secondGameMessage[10];

    // Pacman eats ghost in second game
    serverReplyToMainGame[10] = secondGameMessage[11];
    serverReplyToMainGame[11] = secondGameMessage[12];
    serverReplyToMainGame[12] = secondGameMessage[13];
    serverReplyToMainGame[13] = secondGameMessage[14];
    serverReplyToMainGame[14] = secondGameMessage[15];

    // Server reply to second game

    // Red Ghost
    serverReplyToSecondGame[1] = mainGameMessage[2];
    serverReplyToSecondGame[2] = mainGameMessage[3];
    serverReplyToSecondGame[3] = mainGameMessage[4];
    serverReplyToSecondGame[4] = mainGameMessage[5];

    // Orange Ghost
    serverReplyToSecondGame[5] = mainGameMessage[6];
    serverReplyToSecondGame[6] = mainGameMessage[7];
    serverReplyToSecondGame[7] = mainGameMessage[8];
    serverReplyToSecondGame[8] = mainGameMessage[9];

    // Blue Ghost
    serverReplyToSecondGame[9] = mainGameMessage[10];
    serverReplyToSecondGame[10] = mainGameMessage[11];
    serverReplyToSecondGame[11] = mainGameMessage[12];
    serverReplyToSecondGame[12] = mainGameMessage[13];

    // Pink Ghost
    serverReplyToSecondGame[13] = mainGameMessage[14];
    serverReplyToSecondGame[14] = mainGameMessage[15];
    serverReplyToSecondGame[15] = mainGameMessage[16];
    serverReplyToSecondGame[16] = mainGameMessage[17];

    // Other pacman
    serverReplyToSecondGame[17] = mainGameMessage[18];
    serverReplyToSecondGame[18] = mainGameMessage[19];
    serverReplyToSecondGame[19] = mainGameMessage[20];
    serverReplyToSecondGame[20] = mainGameMessage[21];

    // Score points
    serverReplyToSecondGame[21] =
        ((scorePoints - (scorePoints % 100)) / 100) + '0';
    serverReplyToSecondGame[22] =
        (((scorePoints % 100) - (scorePoints % 10)) / 10) + '0';
    serverReplyToSecondGame[23] = (scorePoints % 10) + '0';

    // Game End Lose
    serverReplyToSecondGame[24] = mainGameMessage[25];

    // End
    serverReplyToMainGame[g_BUFFSIZE - 1] = '\0';
    serverReplyToSecondGame[g_BUFFSIZE - 1] = '\0';

    if (firstClientMessage[0] == '0') {
        if (send(mainGameAcceptSocket, serverReplyToMainGame, g_BUFFSIZE, 0) ==
            SOCKET_ERROR) {
            std::cout << "Failed to send." << std::endl;
        }
        if (send(secondGameAcceptSocket, serverReplyToSecondGame, g_BUFFSIZE,
                 0) == SOCKET_ERROR) {
            std::cout << "Failed to send." << std::endl;
        }
    } else {
        if (send(secondGameAcceptSocket, serverReplyToMainGame, g_BUFFSIZE,
                 0) == SOCKET_ERROR) {
            std::cout << "Failed to send." << std::endl;
        }
        if (send(mainGameAcceptSocket, serverReplyToSecondGame, g_BUFFSIZE,
                 0) == SOCKET_ERROR) {
            std::cout << "Failed to send." << std::endl;
        }
    }

    std::cout << "Sending..." << std::endl;

    memset(&(serverReplyToMainGame), '\0', g_BUFFSIZE);
    memset(&(serverReplyToSecondGame), '\0', g_BUFFSIZE);
}
