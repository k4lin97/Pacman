#include "networkconnection.h"
#include <QDebug>

NetworkConnection::NetworkConnection()
{

}

int NetworkConnection::connectToServer()
{
    serverIPAddress = "127.0.0.1";

    // Inicjalizacja WSA
    result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        qDebug() << "Initialization error.";
        return 1;
    }

    // Utworzenie gniazda TCP
    if ((mainSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        qDebug() << "Error creating socket.";
        WSACleanup();
        return 1;
    }

    // Ustawienie adresu
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(g_PORT);
    srv_addr.sin_addr.s_addr = inet_addr(serverIPAddress.c_str());
    memset(&(srv_addr.sin_zero), '\0', sizeof(srv_addr.sin_zero));

    // Połączenie
    if (::connect(mainSocket, (struct sockaddr*)&srv_addr, sizeof(srv_addr)) == SOCKET_ERROR) {
        qDebug() << "Failed to connect.";
        WSACleanup();
        return 1;
    }

    return 0;
}
