#include "losewindow.h"
#include "ui_losewindow.h"

LoseWindow::LoseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoseWindow)
{
    ui->setupUi(this);
}

LoseWindow::~LoseWindow()
{
    delete ui;
}
