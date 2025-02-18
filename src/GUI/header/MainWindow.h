//
// Created by steff on 17/02/2025.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>

#include "settingswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow  {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private slots:
    void addPlayer();
    void editPlayer();
    void removePlayer();
    void startPokerGame();
    void openSettings();

private:
    Ui::MainWindow *ui;
    SettingsWindow *settingsWindow;
};

#endif //MAINWINDOW_H
