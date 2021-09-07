/**
 * @file choosewindow.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of choosewindow.h.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "choosewindow.h"

#include "ui_choosewindow.h"

ChooseWindow::ChooseWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::ChooseWindow) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle("Choose game!");
    this->setFixedSize(400, 200);

    // IP window
    IPinput = new QLineEdit(this);
    IPinput->setText("127.0.0.1");

    // Buttons
    exitButton = new QPushButton("Exit", this);
    singlePlayerButton = new QPushButton("Single player", this);
    playerOneButton = new QPushButton("Player one", this);
    playerTwoButton = new QPushButton("Player two", this);

    // Connect slots to buttons
    connect(exitButton, SIGNAL(released()), this, SLOT(exitButtonSlot()));
    connect(singlePlayerButton, SIGNAL(released()), this,
            SLOT(singlePlayerButtonSlot()));
    connect(playerOneButton, SIGNAL(released()), this,
            SLOT(playerOneButtonSlot()));
    connect(playerTwoButton, SIGNAL(released()), this,
            SLOT(playerTwoButtonSlot()));

    // Layouts
    singlePlayerButtonsLayout = new QHBoxLayout();
    singlePlayerButtonsLayout->addWidget(singlePlayerButton);

    IPinputLayout = new QHBoxLayout();
    IPinputLayout->addWidget(IPinput);

    multiPlayerButtonsLayout = new QHBoxLayout();
    multiPlayerButtonsLayout->addWidget(playerOneButton);
    multiPlayerButtonsLayout->addWidget(playerTwoButton);

    exitButtonLayout = new QVBoxLayout();
    exitButtonLayout->addWidget(exitButton);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(singlePlayerButtonsLayout);
    mainLayout->addLayout(IPinputLayout);
    mainLayout->addLayout(multiPlayerButtonsLayout);
    mainLayout->addLayout(exitButtonLayout);
    this->setLayout(mainLayout);

    // Create games for multiplayer
    playerOneGame = new MainGameManager(this);
    playerTwoGame = new SecondGameManager(this);

    isMultiplayerActive = false;
}

ChooseWindow::~ChooseWindow() {
    delete ui;

    delete sender;
    delete singlePlayerGame;
    delete playerOneGame;
    delete playerTwoGame;
}

void ChooseWindow::exitButtonSlot() {
    // Close app
    this->close();
    QApplication::quit();
}

void ChooseWindow::singlePlayerButtonSlot() {
    // Create single player game
    singlePlayerGame = new GameManager(this);
    singlePlayerGame->show();
}

void ChooseWindow::playerOneButtonSlot() {
    if (!isMultiplayerActive) {
        std::string ipAddressToConnect =
            IPinput->text().toLocal8Bit().constData();
        isMultiplayerActive = true;
        sender = new MainGameClient();
        // Send and receive data from server
        sender->connectToServer(ipAddressToConnect);
        sender->setGame(playerOneGame);
        sender->startSending();
        playerOneGame->show();
    } else {
        playerOneDialog = new QDialog(this, Qt::WindowTitleHint);
        playerOneDialog->setModal(true);
        playerOneDialog->setFixedSize(200, 100);
        playerOneDialog->setWindowTitle("Player one warning!");

        playerOneDialogCancelButton =
            new QPushButton("Cancel", playerOneDialog);
        playerOneDialogCancelButton->setFixedSize(80, 21);
        playerOneDialogCancelButton->move(60, 59);
        connect(playerOneDialogCancelButton, SIGNAL(released()), this,
                SLOT(playerOneDialogCancelButtonSlot()));

        playerOneDialogLabel = new QLabel(playerOneDialog);
        playerOneDialogLabel->setFixedSize(150, 30);
        playerOneDialogLabel->move(38, 20);
        playerOneDialogLabel->setText("Someone is already playing!");

        playerOneDialog->show();
    }
}

void ChooseWindow::playerTwoButtonSlot() {
    if (!isMultiplayerActive) {
        std::string ipAddressToConnect =
            IPinput->text().toLocal8Bit().constData();
        isMultiplayerActive = true;
        sender = new SecondGameClient();
        // Send and receive data from server
        sender->connectToServer(ipAddressToConnect);
        sender->setGame(playerTwoGame);
        sender->startSending();
        playerTwoGame->show();
    } else {
        playerTwoDialog = new QDialog(this, Qt::WindowTitleHint);
        playerTwoDialog->setModal(true);
        playerTwoDialog->setFixedSize(200, 100);
        playerTwoDialog->setWindowTitle("Player two warning!");

        playerTwoDialogCancelButton =
            new QPushButton("Cancel", playerTwoDialog);
        playerTwoDialogCancelButton->setFixedSize(80, 21);
        playerTwoDialogCancelButton->move(60, 59);
        connect(playerTwoDialogCancelButton, SIGNAL(released()), this,
                SLOT(playerTwoDialogCancelButtonSlot()));

        playerTwoDialogLabel = new QLabel(playerTwoDialog);
        playerTwoDialogLabel->setFixedSize(150, 30);
        playerTwoDialogLabel->move(38, 20);
        playerTwoDialogLabel->setText("Someone is already playing!");

        playerTwoDialog->show();
    }
}

void ChooseWindow::playerOneDialogCancelButtonSlot() {
    playerOneDialog->close();
}

void ChooseWindow::playerTwoDialogCancelButtonSlot() {
    playerTwoDialog->close();
}
