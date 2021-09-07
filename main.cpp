/**
 * @file main.cpp
 * @author Paweł Kalinowski
 * @brief Main class.
 * @version 1.0
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "MainMenu/choosewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChooseWindow w;
    w.show();
    return a.exec();
}
