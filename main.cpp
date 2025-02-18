#include <QApplication>
#include "src/GUI/header/MainWindow.h"
#include "src/header/Poker.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow main_window;
    main_window.show();

    return app.exec();
}
