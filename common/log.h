#ifndef LOG_H
#define LOG_H

class QString;
/*
 * QT_LOGGING_RULES="org.ukui.*=true" UKUI_LOGGING=true ./ukui-sidebar/ukui-sidebar
 */

class Log
{
public:
    static Log* getInstance();
    QString logFile() const;
private:
    explicit Log();
    static Log* sInstance;
    bool mEnable;
};

#endif // LOG_H
