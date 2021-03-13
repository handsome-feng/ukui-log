#include "mainwindow.h"
#include "logging.h"

#include <QApplication>
#include <QStandardPaths>
#include <QDateTime>
#include <QFile>

void ukuiMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    auto logFileName = QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) +
                       QLatin1String("/ukui/ukui-menu.log");
    QString currentTime = QDateTime::currentDateTime().toString("MM-dd hh:mm:ss.zzz");

    QFile file(logFileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        qCWarning(UKUI_MENU) << "Can't open log file: " << logFileName;
        file.close();
        return ;
    }

    QString logMsg;
    switch (type)
    {
    case QtDebugMsg:
        logMsg = QString("%1: [Debug]: %2  Function: %3  File: %4  Line: %5\n").arg(currentTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        break;
    case QtInfoMsg:
        logMsg = QString("%1: [Info]: %2  Function: %3  File: %4  Line: %5\n").arg(currentTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        break;
    case QtWarningMsg:
        logMsg = QString("%1: [Warning]: %2 Function: %3 Line: %4 File: %5\n").arg(currentTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        break;
    case QtCriticalMsg:
        logMsg = QString("%1: [Critical]: %2 Function: %3 Line: %4 File: %5\n").arg(currentTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        break;
    case QtFatalMsg:
        logMsg = QString("%1: [Fatal]: %2 Function: %3 Line: %4 File: %5\n").arg(currentTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        abort();
        break;
    default:
        break;
    }
    file.write(logMsg.toUtf8());
}

int main(int argc, char *argv[])
{
    initLog();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
