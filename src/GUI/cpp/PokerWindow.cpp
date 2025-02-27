//
// Created by steff on 19/02/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PokerWindow.h" resolved

#include "../header/PokerWindow.h"
#include "ui_PokerWindow.h"

PokerWindow::PokerWindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::pokerWindow){
    ui->setupUi(this);

}

PokerWindow::~PokerWindow() {
 delete ui;
}
