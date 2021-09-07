/**
 * @file networkconnection.h
 * @author Paweł Kalinowski
 * @brief Base clas of network connection.
 * @version 1.0
 * @date 2021-09-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef NETWORKCONNECTION_H
#define NETWORKCONNECTION_H

#include "multiplayergamemanager.h"

#include <winsock2.h>
#include <string>

#define g_PORT 27015    // Port to connect
#define g_BUFFSIZE 256  // Size of sending buffer

class NetworkConnection {
   public:
    /**
     * @brief Construct a new Network Connection object.
     *
     */
    NetworkConnection();

    /**
     * @brief Destroy the Network Connection object.
     *
     */
    virtual ~NetworkConnection();

    /**
     * @brief Abstract function for connecting to server.
     *
     * @param _serverIPAddress server IP adress to connect.
     */
    virtual void connectToServer(std::string _serverIPAddress) = 0;

    /**
     * @brief Sets the game object - main game or second game.
     *
     * @param value main or second game.
     */
    void setGame(MultiplayerGameManager *value);

    /**
     * @brief Abstract function - start sending data to server.
     *
     */
    virtual void startSending() = 0;

   private:
    /**
     * @brief Abstract function - prepare message that is being sent to server.
     *
     */
    virtual void prepareMessage() = 0;

   protected:
    MultiplayerGameManager *game;  // Main or second game
};

#endif  // NETWORKCONNECTION_H
