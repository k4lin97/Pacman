/**
 * @file networkconnection.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of networkconnection.h.
 * @version 1.0
 * @date 2021-09-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "networkconnection.h"

NetworkConnection::NetworkConnection() {
    // Empty on purpose
}

NetworkConnection::~NetworkConnection() {
    delete game;
    WSACleanup();
}

void NetworkConnection::setGame(MultiplayerGameManager *value) { game = value; }
