#include "log.h"

#include <QString>
#include <QStandardPaths>
#include <QDateTime>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include <QLoggingCategory>

Log* Log::sInstance = nullptr;

void ukuiMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    auto category = QString::fromLocal8Bit(context.category);
    category.remove(QStringLiteral("org.ukui."));
    auto logFileName = QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) +
                       QLatin1String("/ukui/") + category + ".log";
    QFileInfo fi(logFileName);
    if (!QDir().mkpath(fi.absolutePath())) {
        qWarning() << "Failed to create logging dir" << fi.absolutePath();
    }
    QString currentTime = QDateTime::currentDateTime().toString("MM-dd hh:mm:ss.zzz");

    QFile file(logFileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        qWarning() << "Can't open log file: " << logFileName;
        file.close();
        return ;
    }

    QString logMsg;
    switch (type)
    {
    case QtDebugMsg:
        logMsg = QString("%1: %2 [Debug] %3\n").arg(currentTime).arg(context.category).arg(msg);
        break;
    case QtInfoMsg:
        logMsg = QString("%1: %2 [Info] %3\n").arg(currentTime).arg(context.category).arg(msg);
        break;
    case QtWarningMsg:
        logMsg = QString("%1: %2 [Warning] %3\n").arg(currentTime).arg(context.category).arg(msg);
        break;
    case QtCriticalMsg:
        logMsg = QString("%1: %2 [Critical] %3\n").arg(currentTime).arg(context.category).arg(msg);
        break;
    case QtFatalMsg:
        logMsg = QString("%1: %2 [Fatal] %3\n").arg(currentTime).arg(context.category).arg(msg);
        abort();
        break;
    default:
        break;
    }
    file.write(logMsg.toUtf8());
}

Log* Log::getInstance() {
    if (sInstance == nullptr) {
        sInstance = new Log();
    }
    return sInstance;
}

Log::Log()
{
    const char* logging_env = "UKUI_LOGGING";

    if (qEnvironmentVariableIsSet(logging_env)) {
        const QString logging_env_value = QString::fromUtf8(qgetenv(logging_env));
        if (logging_env_value != QLatin1Char('0') && logging_env_value.toLower() != QLatin1String("false")) {
            mEnable = true;
        }
    }
    if (!mEnable) {
        qInfo() << "logging not enabled!";
        return;
    }
    // The default value is true?
    QLoggingCategory::setFilterRules(QStringLiteral("org.ukui.*=true"));
    qInstallMessageHandler(ukuiMessageOutput);
}
