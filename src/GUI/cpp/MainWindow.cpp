//
// Created by steff on 17/02/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "../header/MainWindow.h"
#include "../../../cmake-build-debug\ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Signale und Slots verbinden
    connect(ui->addPlayerButton, &QPushButton::clicked, this, &MainWindow::addPlayer);
    connect(ui->editPlayerButton, &QPushButton::clicked, this, &MainWindow::editPlayer);
    connect(ui->removePlayerButton, &QPushButton::clicked, this, &MainWindow::removePlayer);
    connect(ui->playPokerButton, &QPushButton::clicked, this, &MainWindow::startPokerGame);
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::openSettings);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addPlayer() {
    bool ok;
    QString name = QInputDialog::getText(this,"Add Player","Enter Player Name:",QLineEdit::Normal,"",&ok);
    if (ok && !name.isEmpty()) {
        ui->playerListWidget->addItem(name);
    }
}

void MainWindow::editPlayer() {
    QListWidgetItem *item = ui->playerListWidget->currentItem();
    if (item) {
        bool ok;
        QString newName = QInputDialog::getText(this,"Edit Player Name","Enter new name",QLineEdit::Normal,"",&ok);
        if (ok && !newName.isEmpty()) {
            item->setText(newName);
        }
    } else {
        QMessageBox::warning(this,"Edit error","Please select a player to edit");
    }
}

void MainWindow::removePlayer() {
    QListWidgetItem *item = ui->playerListWidget->currentItem();
    if (item) {
        delete item;
    }else {
        QMessageBox::warning(this,"Edit error","Please select a player to delete");
    }
}

void MainWindow::startPokerGame() {
    //TODO
}

void MainWindow::openSettings() {
    settingsWindow = new SettingsWindow(this);
    settingsWindow->setModal(true);
    settingsWindow->show();
}

