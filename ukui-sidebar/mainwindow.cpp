#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ukuisidebar_debug.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qCInfo(UKUI_SIDEBAR()) << "Info something in sidebar";
    qCDebug(UKUI_SIDEBAR()) << "Debug something in sidebar";
    qCWarning(UKUI_SIDEBAR()) << "Warning someting sidebar";
    qCCritical(UKUI_SIDEBAR()) << "Something Critical sidebar";
}

MainWindow::~MainWindow()
{
    delete ui;
}
