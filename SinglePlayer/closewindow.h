/**
 * @file closewindow.h
 * @author Paweł Kalinowski
 * @brief Closing window.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef CLOSEWINDOW_H
#define CLOSEWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>

namespace Ui {
class CloseWindow;
}

class CloseWindow : public QDialog {
    Q_OBJECT

   public:
    /**
     * @brief Construct a new Close Window object.
     *
     * @param _score player's score.
     * @param _win did the player win.
     * @param parent QDialog parent.
     */
    CloseWindow(int _score, bool _win, QWidget *parent = nullptr);

    /**
     * @brief Destroy the Close Window object.
     *
     */
    ~CloseWindow();

   private slots:
    /**
     * @brief Function called after pressing the exit button.
     *
     */
    void exitButtonSlot();

   private:
    Ui::CloseWindow *ui;

    QPushButton *exitButton;
    QVBoxLayout *mainLayout;
    QLabel *label;
};

#endif  // CLOSEWINDOW_H
