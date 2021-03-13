#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ukuimenu_debug.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLoggingCategory::setFilterRules(QStringLiteral("org.ukui.*=false"));

    qCInfo(UKUI_MENU) << "Info something in menu";
    qCDebug(UKUI_MENU) << "Debug something in menu";
    qCWarning(UKUI_MENU) << "Warning someting in menu";
    qCCritical(UKUI_MENU) << "Something Critical in menu";
}

MainWindow::~MainWindow()
{
    delete ui;
}
