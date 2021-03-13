#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "log.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qCInfo(UKUI_MENU) << "Info something";
    qCDebug(UKUI_MENU) << "Debug something";
    qCWarning(UKUI_MENU) << "Warning someting";
    qCCritical(UKUI_MENU) << "Something Critical";
}

MainWindow::~MainWindow()
{
    delete ui;
}
