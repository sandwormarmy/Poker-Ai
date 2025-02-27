//
// Created by steff on 19/02/2025.
//

#ifndef POKERSETTINGSWINDOW_H
#define POKERSETTINGSWINDOW_H

#include <QWidget>
#include <QStringList>

#include "PokerWindow.h"
#include "ui_MainWindow.h"

#include "../../header/Player.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class PokerSettingsPage : public QWidget {
Q_OBJECT

public:
    explicit PokerSettingsPage(Ui::MainWindow *mainUi,QWidget *parent);
    ~PokerSettingsPage() override;
    void setPlayers(const QStringList&);

private:
    Ui::MainWindow *ui;
    PokerWindow *pokerWindow;

    unsigned int balance = 0;
    unsigned int bigBlind = 0;
    /**
   * checks for validity of variables
     * creates errors for problems
     * @return true if all good
    */
    bool pregameCheck();
    QStringList getPlayersfromWidget() const;

private slots:
    void addAIPlayer();
    void removeAIPlayer();
    void PlayPoker();
    void toMain();


 signals:
        void playersUpdated(const QStringList &players);

};


#endif //POKERSETTINGSWINDOW_H
