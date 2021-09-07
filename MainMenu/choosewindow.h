/**
 * @file choosewindow.h
 * @author Paweł Kalinowski
 * @brief Class responsible for creating the main menu.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include "SinglePlayer/gamemanager.h"
#include "MultiPlayer/maingamemanager.h"
#include "MultiPlayer/secondgamemanager.h"
#include "MultiPlayer/maingameclient.h"
#include "MultiPlayer/secondgameclient.h"

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QLineEdit>

namespace Ui {
class ChooseWindow;
}

class ChooseWindow : public QDialog {
    Q_OBJECT

   public:
    /**
     * @brief Construct a new Choose Window object.
     *
     * @param parent Parent of a QDialog.
     */
    explicit ChooseWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroy the Choose Window object.
     *
     */
    ~ChooseWindow();

   private slots:
    /**
     * @brief Function called after pressing the exit button.
     *
     */
    void exitButtonSlot();

    /**
     * @brief Function called after pressing the singleplayer button.
     *
     */
    void singlePlayerButtonSlot();

    /**
     * @brief Function called after pressing the player one button.
     *
     */
    void playerOneButtonSlot();

    /**
     * @brief Function called after pressing the player two button.
     *
     */
    void playerTwoButtonSlot();

    /**
     * @brief Function called after closing player one dialog.
     *
     */
    void playerOneDialogCancelButtonSlot();

    /**
     * @brief Function called after closing player two dialog.
     *
     */
    void playerTwoDialogCancelButtonSlot();

   private:
    Ui::ChooseWindow *ui;

    NetworkConnection
        *sender;  // Used for sending and receiving data from server

    QDialog *playerOneDialog;
    QDialog *playerTwoDialog;

    QPushButton *playerOneDialogCancelButton;
    QPushButton *playerTwoDialogCancelButton;

    QPushButton *exitButton;
    QPushButton *singlePlayerButton;
    QPushButton *playerOneButton;
    QPushButton *playerTwoButton;

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

    QLineEdit *IPinput;

    bool isMultiplayerActive;
};

#endif  // CHOOSEWINDOW_H
