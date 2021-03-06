#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QApplication>
#include <QProcess>
#include <QFileDialog>
#include <QInputDialog>

#include "mainwindow.h"
#include "modelworld.h"
#include "strategy.h"
#include "graphicalview.h"
#include "mygraphicsscene.h"
#include "commandup.h"
#include "commanddown.h"
#include "commandleft.h"
#include "commandright.h"
#include "command.h"
#include "commandzoomin.h"
#include "commandzoomout.h"
#include "commandpandown.h"
#include "commandpanleft.h"
#include "commandpanright.h"
#include "commandpanup.h"
#include "commandtogglepathfinding.h"
#include "commandtogglestrategy.h"
#include "textview.h"

class MainController : public QObject
{
public:
    MainController(QApplication& a);
    ~MainController() override = default;
    int startGameInstance();

private:
    QApplication& app;

public slots:
    void quitApp();
    void openNewWorld();
};

#endif // MAINCONTROLLER_H
