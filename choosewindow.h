#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include "gamemanager.h"
#include "maingamemanager.h"
#include "secondgamemanager.h"
#include "client.h"

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QLineEdit>

namespace Ui {
class ChooseWindow;
}

class ChooseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseWindow(QWidget *parent = nullptr);
    ~ChooseWindow();

private slots:
    void exitButtonSlot();
    void singlePlayerButtonSlot();
    void connectToServerButtonSlot();
    void playerOneButtonSlot();
    void playerTwoButtonSlot();

    void connectToServerDialogCancelButtonSlot();
    void playerOneDialogCancelButtonSlot();
    void playerTwoDialogCancelButtonSlot();

private:
    Ui::ChooseWindow *ui;

    Client *sender;

    QDialog *connectToServerDialog;
    QDialog *playerOneDialog;
    QDialog *playerTwoDialog;

    QPushButton *connectToServerDialogCancelButton;
    QPushButton *playerOneDialogCancelButton;
    QPushButton *playerTwoDialogCancelButton;

    QPushButton *exitButton;
    QPushButton *singlePlayerButton;
    QPushButton *connectToServerButton;
    QPushButton *playerOneButton;
    QPushButton *playerTwoButton;

    QLabel *connectToServerDialogLabel;
    QLabel *playerOneDialogLabel;
    QLabel *playerTwoDialogLabel;

    QVBoxLayout *mainLayout;
    QHBoxLayout *singlePlayerButtonsLayout;
    QHBoxLayout *multiPlayerButtonsLayout;
    QVBoxLayout *exitButtonLayout;
    QHBoxLayout *IPinputLayout;

    GameManager *singlePlayerGame;
    MainGameManager *playerOneGame;
    SecondGameManager *playerTwoGame;

    bool isConnectedToServer;
    bool isPlayerOnePlaying;
    bool isPlayerTwoPlaying;

    QLineEdit *IPinput;
};

#endif // CHOOSEWINDOW_H
