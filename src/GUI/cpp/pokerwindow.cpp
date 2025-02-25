//
// Created by steff on 19/02/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PokerWindow.h" resolved

#include "../header/pokerwindow.h"
#include "../../header/Player.h"


PokerWindow::PokerWindow(Ui::MainWindow *mainUi,QWidget *parent) :
    QWidget(parent), ui(mainUi) {

}

PokerWindow::~PokerWindow() {

}
