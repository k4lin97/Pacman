#include "choosewindow.h"
#include "ui_choosewindow.h"

ChooseWindow::ChooseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    isConnectedToServer = false;
    isPlayerOnePlaying = false;
    isPlayerTwoPlaying = false;

    this->setWindowTitle("Choose game!");
    this->setFixedSize(400, 200);

    IPinput = new QLineEdit(this);
    IPinput->setText("127.0.0.1");

    exitButton = new QPushButton("Exit", this);
    singlePlayerButton = new QPushButton("Single player", this);
    connectToServerButton = new QPushButton("Connect to server", this);
    playerOneButton = new QPushButton("Player one", this);
    playerTwoButton = new QPushButton("Player two", this);

    connect(exitButton, SIGNAL(released()), this, SLOT(exitButtonSlot()));
    connect(singlePlayerButton, SIGNAL(released()), this, SLOT(singlePlayerButtonSlot()));
    connect(connectToServerButton, SIGNAL(released()), this, SLOT(connectToServerButtonSlot()));
    connect(playerOneButton, SIGNAL(released()), this, SLOT(playerOneButtonSlot()));
    connect(playerTwoButton, SIGNAL(released()), this, SLOT(playerTwoButtonSlot()));

    singlePlayerButtonsLayout = new QHBoxLayout();
    singlePlayerButtonsLayout->addWidget(singlePlayerButton);

    IPinputLayout = new QHBoxLayout();
    IPinputLayout->addWidget(IPinput);

    multiPlayerButtonsLayout = new QHBoxLayout();
    multiPlayerButtonsLayout->addWidget(connectToServerButton);
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

    playerOneGame = new MainGameManager(this);
    playerTwoGame = new SecondGameManager(this);
}

ChooseWindow::~ChooseWindow()
{
    delete ui;

    delete sender;

    /*delete serverDialog;
    delete clientDialog;
    delete compileServerDialog;

    delete mainLayout;
    delete singleplayerButtonsLayout;
    delete multiplayerButtonsLayout;
    delete exitButtonLayout;

    delete serverDialogCancelButton;
    delete clientDialogCancelButton;
    delete compileServerDialogCancelButton;

    delete exitButton;
    delete singleButton;
    delete serverButton;
    delete compileServerButton;
    delete clientButton;

    delete serverDialogLabel;
    delete clientDialogLabel;
    delete serverCompileLabel;

    delete IPinputLayout;
    delete IPinput;*/

    delete singlePlayerGame;
    delete playerOneGame;
    delete playerTwoGame;
}

void ChooseWindow::exitButtonSlot()
{
    this->close();
    QApplication::quit();
}

void ChooseWindow::singlePlayerButtonSlot()
{
    singlePlayerGame = new GameManager(this);
    singlePlayerGame->show();
}

void ChooseWindow::connectToServerButtonSlot()
{
    std::string ipAddressToConnect = IPinput->text().toLocal8Bit().constData();
    if(!isConnectedToServer) {
        sender = new Client(playerOneGame, playerTwoGame);
        if (sender->connectToServer(ipAddressToConnect) == 0) {
            isConnectedToServer = true;
        } else {
            isConnectedToServer = false;
        }
    } else {
        connectToServerDialog = new QDialog(this, Qt::WindowTitleHint);
        connectToServerDialog->setModal(true);
        connectToServerDialog->setFixedSize(200, 100);
        connectToServerDialog->setWindowTitle("Connection warning!");

        connectToServerDialogCancelButton = new QPushButton("Cancel", connectToServerDialog);
        connectToServerDialogCancelButton->setFixedSize(80, 21);
        connectToServerDialogCancelButton->move(60, 59);
        connect(connectToServerDialogCancelButton, SIGNAL(released()), this, SLOT(connectToServerDialogCancelButtonSlot()));

        connectToServerDialogLabel = new QLabel(connectToServerDialog);
        connectToServerDialogLabel->setFixedSize(150, 30);
        connectToServerDialogLabel->move(38, 20);
        connectToServerDialogLabel->setText("Already connected to server!");

        connectToServerDialogLabel->show();
    }
}

void ChooseWindow::playerOneButtonSlot()
{
    if (!isPlayerOnePlaying) {
        isPlayerOnePlaying = true;
        playerOneGame->show();
        sender->startSending();
    } else {
        playerOneDialog = new QDialog(this, Qt::WindowTitleHint);
        playerOneDialog->setModal(true);
        playerOneDialog->setFixedSize(200, 100);
        playerOneDialog->setWindowTitle("Player one warning!");

        playerOneDialogCancelButton = new QPushButton("Cancel", playerOneDialog);
        playerOneDialogCancelButton->setFixedSize(80, 21);
        playerOneDialogCancelButton->move(60, 59);
        connect(playerOneDialogCancelButton, SIGNAL(released()), this, SLOT(playerOneDialogCancelButtonSlot()));

        playerOneDialogLabel = new QLabel(playerOneDialog);
        playerOneDialogLabel->setFixedSize(150, 30);
        playerOneDialogLabel->move(38, 20);
        playerOneDialogLabel->setText("Player one is already playing!");

        playerOneDialog->show();
    }
}

void ChooseWindow::playerTwoButtonSlot()
{
    if (!isPlayerTwoPlaying) {
        isPlayerTwoPlaying = true;
        playerTwoGame->show();
    } else {
        playerTwoDialog = new QDialog(this, Qt::WindowTitleHint);
        playerTwoDialog->setModal(true);
        playerTwoDialog->setFixedSize(200, 100);
        playerTwoDialog->setWindowTitle("Player two warning!");

        playerTwoDialogCancelButton = new QPushButton("Cancel", playerTwoDialog);
        playerTwoDialogCancelButton->setFixedSize(80, 21);
        playerTwoDialogCancelButton->move(60, 59);
        connect(playerTwoDialogCancelButton, SIGNAL(released()), this, SLOT(playerTwoDialogCancelButtonSlot()));

        playerTwoDialogLabel = new QLabel(playerTwoDialog);
        playerTwoDialogLabel->setFixedSize(150, 30);
        playerTwoDialogLabel->move(38, 20);
        playerTwoDialogLabel->setText("Player two is already playing!");

        playerTwoDialog->show();
    }
}

void ChooseWindow::connectToServerDialogCancelButtonSlot()
{
    connectToServerDialog->close();
}

void ChooseWindow::playerOneDialogCancelButtonSlot()
{
    playerOneDialog->close();
}

void ChooseWindow::playerTwoDialogCancelButtonSlot()
{
    playerTwoDialog->close();
}
