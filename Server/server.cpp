#include <winsock2.h>

#include <iostream>
#include <string>

#define g_PORT 27015
#define g_BUFFSIZE 64

#define map_height 31
#define map_width 28

const char *BREAK_MESSAGE = "#";
const char *BREAK_DATA = "$";

char mainGamePaused;
char secondGamePaused;

int scorePoints;

char mainClientMessage[g_BUFFSIZE] = "";  // ROZKMINIĆ JAKI POWINIEN BYĆ ROZMIAR
char secondClientMessage[g_BUFFSIZE / 2] = "";

SOCKET mainSocket;  // Główne gniazdo

void processData(char *recievedBuffer);
void sendToClient();
int findChar(char *my_array, const char *my_char);

int main() {
    std::string serverIPAddress = "127.0.0.1";
    //std::cout << "Podaj adres IP. Dla jednej maszyny 127.0.0.1" << std::endl;
    //std::cin >> serverIPAddress;
    while (true) {
        mainGamePaused = '1';  // 1 - true
        secondGamePaused = '1';

        scorePoints = 0;
        

        WSADATA wsaData;
        int result;

        // Inicjalizacja wsa
        result = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (result != 0) {
            std::cout << "Initialization error." << std::endl;
            return 1;
        }

        // Utworzenie gniazda TCP
        // SOCKET mainSocket;  // Główne gniazdo
        if ((mainSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
            std::cout << "Error creating socket." << std::endl;
            WSACleanup();
            return 1;
        }

        // Ustawienie adresu
        sockaddr_in srv_addr;  // Mój adres
        srv_addr.sin_family = AF_INET;
        srv_addr.sin_port = htons(g_PORT);
        srv_addr.sin_addr.s_addr = inet_addr(serverIPAddress.c_str());
        memset(&(srv_addr.sin_zero), '\0', sizeof(srv_addr.sin_zero));

        // Bindowanie stworzonego gniazda (przypisanie go do adresu)
        if (bind(mainSocket, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) ==
            SOCKET_ERROR) {
            std::cout << "Error creating socket." << std::endl;
            closesocket(mainSocket);
            WSACleanup();
            return 1;
        }

        // Tutaj serwer może już nasłuchiwać na wybranym porcie
        if (listen(mainSocket, 1) == SOCKET_ERROR) {
            std::cout << "Error listening on socket." << std::endl;
            WSACleanup();
            return 1;
        }

        // Funkcja accept przyjmuje próbę połączenia od klienta
        // i zwraca wskaźnik na gniazdo, które służy do komunikacji z danym
        // klientem SOCKET_ERROR jest zwracany gdy jet błąd lub żaden klient nie
        // próbował się połączyć
        SOCKET acceptSocket = SOCKET_ERROR;
        std::cout << "Waiting for a client to connect..." << std::endl;

        while (acceptSocket == SOCKET_ERROR) {
            acceptSocket = accept(mainSocket, NULL, NULL);
        }

        std::cout << "Client connected." << std::endl;
        // Zastępujemy uchwyt naszego gniazda tym otrzymanym z accept – tamto
        // było potrzebne tylko do połączenia się z klientem
        mainSocket = acceptSocket;

        int bytesRecv = SOCKET_ERROR;
        char recvBuff[g_BUFFSIZE] = "";

        do {
            bytesRecv = recv(mainSocket, recvBuff, g_BUFFSIZE, 0);
            // std::cout << "Received text: " << recvBuff << std::endl;
            processData(recvBuff);
            sendToClient();
        } while (bytesRecv > 0);

        // system("pause");
        system("cls");
        closesocket(acceptSocket);
        closesocket(mainSocket);
        WSACleanup();
    }
    return 0;
}

void processData(char *recievedBuffer) {
    std::cout << "Received text: " << recievedBuffer << std::endl;

    int position = findChar(recievedBuffer, BREAK_MESSAGE);
    if (position != -1) {
        memcpy(mainClientMessage, recievedBuffer, position);
        memcpy(secondClientMessage, (recievedBuffer + position + 1),
               strlen(recievedBuffer) / 2);
    }

    std::cout << "mainClientMessage 1: " << mainClientMessage << std::endl;
    std::cout << "secondClientMessage 2: " << secondClientMessage << std::endl;
}

void sendToClient() {
    char serverReply[g_BUFFSIZE] = "";
    memset(&serverReply, '@', g_BUFFSIZE);

    if (mainClientMessage[0] != mainGamePaused) {
        // std::cout << "Zmiana w pierwszej" << std::endl;
        mainGamePaused = mainClientMessage[0];
        secondGamePaused = mainClientMessage[0];
        serverReply[0] = '1';
    } else if (secondClientMessage[0] != secondGamePaused) {
        // std::cout << "Zmiana w drugiej" << std::endl;
        secondGamePaused = secondClientMessage[0];
        mainGamePaused = secondClientMessage[0];
        serverReply[1] = '1';
    }
    // Red Ghost
    serverReply[2] = mainClientMessage[2];
    serverReply[3] = mainClientMessage[3];
    serverReply[4] = mainClientMessage[4];
    serverReply[5] = mainClientMessage[5];

    // Orange Ghost
    serverReply[6] = mainClientMessage[6];
    serverReply[7] = mainClientMessage[7];
    serverReply[8] = mainClientMessage[8];
    serverReply[9] = mainClientMessage[9];

    // Blue Ghost
    serverReply[10] = mainClientMessage[10];
    serverReply[11] = mainClientMessage[11];
    serverReply[12] = mainClientMessage[12];
    serverReply[13] = mainClientMessage[13];

    // Pink Ghost
    serverReply[14] = mainClientMessage[14];
    serverReply[15] = mainClientMessage[15];
    serverReply[16] = mainClientMessage[16];
    serverReply[17] = mainClientMessage[17];

    // Main Game Pacman
    serverReply[18] = mainClientMessage[19];
    serverReply[19] = mainClientMessage[20];
    serverReply[20] = mainClientMessage[21];
    serverReply[21] = mainClientMessage[22];

    // Second Game Pacman
    serverReply[22] = secondClientMessage[2];
    serverReply[23] = secondClientMessage[3];
    serverReply[24] = secondClientMessage[4];
    serverReply[25] = secondClientMessage[5];

    // Score Points
    int mainScorePoints = ((mainClientMessage[24] - '0') * 100) +
                          ((mainClientMessage[25] - '0') * 10) +
                          (mainClientMessage[26] - '0');
    int secondScorePoints = ((secondClientMessage[7] - '0') * 100) +
                            ((secondClientMessage[8] - '0') * 10) +
                            (secondClientMessage[9] - '0');
    scorePoints = mainScorePoints + secondScorePoints;

    serverReply[26] = ((scorePoints - (scorePoints % 100)) / 100) + '0';
    serverReply[27] = (((scorePoints % 100) - (scorePoints % 10)) / 10) + '0';
    serverReply[28] = (scorePoints % 10) + '0';

    // Game End Lose
    serverReply[29] = mainClientMessage[28];
    serverReply[30] = secondClientMessage[11];

    // End
    serverReply[g_BUFFSIZE - 1] = '\0';

    if (send(mainSocket, serverReply, strlen(serverReply), 0) == SOCKET_ERROR) {
        std::cout << "Failed to send." << std::endl;
    }
    std::cout << "Server reply: " << serverReply << std::endl;
}

/*
returns position of a char or -1 if not found
*/
int findChar(char *my_array, const char *my_char) {
    int result = -1;
    for (int i = 0; i < strlen(my_array); i++) {
        if (my_array[i] == *my_char) {
            result = i;
            break;
        }
    }
    return result;
}
