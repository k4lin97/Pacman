#ifndef CLIENT_H
#define CLIENT_H

#include "maingamemanager.h"
#include "secondgamemanager.h"
#include "networkconnection.h"

#include <winsock2.h>
#include <string>



class Client : public QDialog, public NetworkConnection
{
    Q_OBJECT

public:
    Client(MainGameManager *_mainGame, SecondGameManager *_secondGame);
    ~Client();

    void startSending();
    void prepareMessage();

private slots:
    int sendToServer();
    void reciveFromServer();

private:
    MainGameManager *mainGame;
    SecondGameManager *secondGame;

    const std::string BREAK_MESSAGE = "#";
    const std::string BREAK_DATA = "$";
    /*
     * MOZE LEPIEJ TO ZMIENIC
     * */

    std::string stringMessage;
    char sendBuff[g_BUFFSIZE] = "";
    char recvBuff[g_BUFFSIZE] = "";
};

#endif // CLIENT_H
