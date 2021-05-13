#ifndef CLOSEWINDOW_H
#define CLOSEWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>

namespace Ui {
class CloseWindow;
}

class CloseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CloseWindow(int score, bool win, QWidget *parent = nullptr);
    ~CloseWindow();

private slots:
    void exitButtonSlot();

private:
    Ui::CloseWindow *ui;

    QPushButton *exitButton;

    QVBoxLayout *mainLayout;

    QLabel *label;
};

#endif // CLOSEWINDOW_H
