/**
 * @file secondgameclient.h
 * @author Paweł Kalinowski
 * @brief Second game client class.
 * @version 1.0
 * @date 2021-09-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef SECONDGAMECLIENT_H
#define SECONDGAMECLIENT_H

#include "networkconnection.h"

#include <winsock2.h>
#include <string>

class SecondGameClient : public QDialog, public NetworkConnection {
    Q_OBJECT

   public:
    /**
     * @brief Construct a new Second Game Client object.
     *
     * @param parent QDialog parent.
     */
    SecondGameClient(QWidget *parent = nullptr);

    /**
     * @brief Destroy the Second Game Client object.
     *
     */
    ~SecondGameClient();

    /**
     * @brief Connects to server on specified IP adress.
     *
     * @param _serverIPAddress server IP adress to which client connects.
     */
    void connectToServer(std::string _serverIPAddress) override;

    /**
     * @brief Connects game timer with sending function.
     *
     */
    void startSending() override;

   private slots:
    /**
     * @brief Function that sends data to server.
     *
     * First the data is received from server. Then the message is prepared.
     * At the end client sends data to server.
     */
    void sendToServer();

    /**
     * @brief Function that interprets data from server.
     *
     */
    void reciveFromServer();

   private:
    /**
     * @brief Prepares a message that is send to server.
     *
     */
    void prepareMessage() override;

    std::string serverIPAddress;  // Server IP adress

    WSADATA wsaData;
    SOCKET mainSocket;     // Main socket
    sockaddr_in srv_addr;  // My adress

    int result;

    char sendBuff[g_BUFFSIZE] = "";  // Data sent to server
    char recvBuff[g_BUFFSIZE] = "";  // Data received from server
};

#endif  // SECONDGAMECLIENT_H
