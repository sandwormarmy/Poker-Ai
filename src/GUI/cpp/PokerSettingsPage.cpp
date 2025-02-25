//
// Created by steff on 19/02/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PokerSettingsWindow.h" resolved

#include <QMessageBox>

#include "../header/PokerSettingsPage.h"

PokerSettingsPage::PokerSettingsPage(Ui::MainWindow *mainUi,QWidget *parent) :
    QWidget(parent), ui(mainUi) {

    connect(ui->playPokerButton_2, &QPushButton::clicked, this, &PokerSettingsPage::PlayPoker);
    connect(ui->addAIButton, &QPushButton::clicked, this, &PokerSettingsPage::addAIPlayer);
    connect(ui->removeAIButton, &QPushButton::clicked, this, &PokerSettingsPage::removeAIPlayer);
    connect(ui->backButton, &QPushButton::clicked, this, &PokerSettingsPage::toMain);
}

void PokerSettingsPage::setPlayers(const QStringList &players) {
    ui->playerListWidget->clear();
    ui->playerList->addItems(players);
}

PokerSettingsPage::~PokerSettingsPage() = default;

void PokerSettingsPage::addAIPlayer() {
    QMessageBox::information(this,"no","nein");
}

void PokerSettingsPage::removeAIPlayer() {
    QMessageBox::information(this,"no","nein");
}

void PokerSettingsPage::PlayPoker() {
    // dosnt show errrors ??
    std::cout << "hier"<<std::endl;
    auto wow = pregameCheck();
    if (wow) {
        //pokerPage = new PokerPage(ui, this);
        //ui->stackedWidget->addWidget(PokerPage);
        ui->stackedWidget->setCurrentWidget(ui->PokerPage);
    }
}

void PokerSettingsPage::toMain() {
    emit playersUpdated(getPlayersfromWidget());
    ui->stackedWidget->setCurrentWidget(ui->mainPage);
}

bool PokerSettingsPage::pregameCheck() {

    bool check = true;
    bool ok = false;
    // balance Relatet checks
    if (ui->balanceInput->toPlainText().toInt(&ok) == 0 ||!ok) {
        check =false;
        QMessageBox::information(this,"no Balance","Balance cant be 0");
    }
    // bigblind Relatet checks
    if (ui->bigBlindInput->toPlainText().toInt(&ok) == 0 ||!ok) {
        check =false;
        QMessageBox::information(this,"no big-blind","big-blind cant be 0");
    }
    // players Relatet checks
    if (getPlayersfromWidget().size() < 2) {
        check =false;
        QMessageBox::information(this,"Not enough players","At least 2 Players needed");
    }

    return check;
}

QStringList PokerSettingsPage::getPlayersfromWidget() const {
    QStringList updatedPlayers;
    for (int i = 0; i < ui->playerList->count(); ++i) {
        updatedPlayers << ui->playerList->item(i)->text();
    }
    return updatedPlayers;
}
