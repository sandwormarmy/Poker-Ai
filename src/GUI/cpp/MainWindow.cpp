//
// Created by steff on 17/02/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include <QInputDialog>
#include <QMessageBox>
#include <QLayout>

#include "../header/MainWindow.h"
#include "../../../cmake-build-debug\ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    pokerSettingsPage = new PokerSettingsPage(ui, this);
    ui->stackedWidget->addWidget(pokerSettingsPage);

    // Signale und Slots verbinden
    std::cout << "why4"<<std::endl;
    connect(ui->addPlayerButton, &QPushButton::clicked, this, &MainWindow::addPlayer);
    connect(ui->editPlayerButton, &QPushButton::clicked, this, &MainWindow::editPlayer);
    connect(ui->removePlayerButton, &QPushButton::clicked, this, &MainWindow::removePlayer);
    connect(ui->playPokerButton, &QPushButton::clicked, this, &MainWindow::startPokerGame);
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::openSettings);
    std::cout << "kaa"<<std::endl;
    connect(pokerSettingsPage, &PokerSettingsPage::playersUpdated, this, &MainWindow::updatePlayerList);
    std::cout << "kaa"<<std::endl;
}

MainWindow::~MainWindow() {
    delete ui;
    delete settingsWindow;
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
        QMessageBox::information(this,"Edit error","Please select a player to edit");
    }
}

void MainWindow::removePlayer() {
    QListWidgetItem *item = ui->playerListWidget->currentItem();
    if (item) {
        delete item;
    }else {
        QMessageBox::information(this,"Edit error","Please select a player to delete");
    }
}

void MainWindow::startPokerGame() {

    QStringList items;
    for (int i = 0; i < ui->playerListWidget->count(); ++i) {
        items << ui->playerListWidget->item(i)->text();
    }
    pokerSettingsPage->setPlayers(items);
    ui->stackedWidget->setCurrentWidget(ui->PokerSettingsPage);
}

void MainWindow::openSettings() {
    settingsWindow = new SettingsWindow(this);
    settingsWindow->setModal(true);
    settingsWindow->show();
}

void MainWindow::updatePlayerList(const QStringList &players) {
    ui->playerListWidget->clear();
    ui->playerListWidget->addItems(players);
}