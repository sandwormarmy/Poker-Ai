//
// Created by steff on 19/02/2025.
//

#ifndef POKERWINDOW_H
#define POKERWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class PokerWindow : public QWidget {
Q_OBJECT

public:
    explicit PokerWindow(Ui::MainWindow*,QWidget *parent = nullptr);
    ~PokerWindow() override;

private:
    Ui::MainWindow *ui;
};


#endif //POKERWINDOW_H
