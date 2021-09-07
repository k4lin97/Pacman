/**
 * @file maingameclient.h
 * @author Paweł Kalinowski
 * @brief Main game client class.
 * @version 1.0
 * @date 2021-09-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef MAINGAMECLIENT_H
#define MAINGAMECLIENT_H

#include "networkconnection.h"

#include <winsock2.h>
#include <string>

class MainGameClient : public QDialog, public NetworkConnection {
    Q_OBJECT

   public:
    /**
     * @brief Construct a new Main Game Client object.
     *
     * @param parent QDialog parent.
     */
    MainGameClient(QWidget *parent = nullptr);

    /**
     * @brief Destroy the Main Game Client object.
     *
     */
    ~MainGameClient();

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

    /**
     * @brief Prepares a message that is send to server.
     *
     */
    void prepareMessage() override;

   private slots:
    /**
     * @brief Function that sends data to server.
     *
     * First the data is received from server. Then the message is prepared.
     * At the end client sends data to server.
     */
    void sendToServer();

   private:
    /**
     * @brief Function that interprets data from server.
     *
     */
    void reciveFromServer();

    std::string serverIPAddress;  // Server IP adress

    WSADATA wsaData;
    SOCKET mainSocket;     // Main soscket
    sockaddr_in srv_addr;  // My adress

    int result;

    char sendBuff[g_BUFFSIZE] = "";  // Data sent to server
    char recvBuff[g_BUFFSIZE] = "";  // Data received from server
};

#endif  // MAINGAMECLIENT_H
