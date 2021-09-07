/**
 * @file closewindow.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of closewindow.h.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "closewindow.h"

#include "ui_closewindow.h"

CloseWindow::CloseWindow(int _score, bool _win, QWidget *parent)
    : QDialog(parent), ui(new Ui::CloseWindow) {
    ui->setupUi(this);

    QString text = _win ? "You win!" : "You lose!";

    this->setWindowTitle(text);
    this->setFixedSize(400, 200);

    exitButton = new QPushButton("Exit", this);

    connect(exitButton, SIGNAL(released()), this, SLOT(exitButtonSlot()));

    label = new QLabel(this);

    label->setText(text + " Your score: " + QString::number(_score) + "!");
    label->setAlignment(Qt::AlignCenter);

    mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(label);
    mainLayout->addWidget(exitButton);

    this->setLayout(mainLayout);
}

CloseWindow::~CloseWindow() { delete ui; }

void CloseWindow::exitButtonSlot() { this->close(); }
