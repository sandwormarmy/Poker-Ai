//
// Created by steff on 18/02/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SettingsWindow.h" resolved

#include "../header/settingswindow.h"
#include "ui_SettingsWindow.h"


SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::SettingsWindow) {
    ui->setupUi(this);
    setWindowTitle("Settings");
}

SettingsWindow::~SettingsWindow() {
    delete ui;
}
