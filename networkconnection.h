#ifndef NETWORKCONNECTION_H
#define NETWORKCONNECTION_H
#include <winsock2.h>
#include <string>

#define g_PORT 27015
#define g_BUFFSIZE 64

class NetworkConnection
{
public:
    NetworkConnection();
    int connectToServer();

protected:
    std::string serverIPAddress;

    WSADATA wsaData;
    SOCKET mainSocket;  // Główne gniazdo
    sockaddr_in srv_addr;  // Mój adres

    int result;
};

#endif // NETWORKCONNECTION_H
