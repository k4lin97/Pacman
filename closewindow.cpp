#include "closewindow.h"
#include "ui_closewindow.h"

CloseWindow::CloseWindow(int score, bool win, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CloseWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    QString text = win ? "You win!" : "You lose!";

    this->setWindowTitle(text);
    this->setFixedSize(400, 200);

    exitButton = new QPushButton("Exit", this);

    connect(exitButton, SIGNAL(released()), this, SLOT(exitButtonSlot()));

    label = new QLabel(this);

    label->setText(text + " Your score: " + QString::number(score) + "!");
    label->setAlignment(Qt::AlignCenter);

    mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(label);
    mainLayout->addWidget(exitButton);

    this->setLayout(mainLayout);
}

CloseWindow::~CloseWindow()
{
    delete ui;

    delete exitButton;

    delete mainLayout;

    delete label;
}

void CloseWindow::exitButtonSlot()
{
    this->close();
}
