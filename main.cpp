#include <QCoreApplication>
#include <QApplication>
#include <QSettings>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <QFile>

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    QSettings setting("option.ini",QSettings::IniFormat);
    QString fileName = setting.value("GuardianFile").toString();
    if(fileName == ""
            || (!QFile::exists(fileName)) )
    {
        QMessageBox::warning(NULL, "Warning", QString("Daemon exit by fileName(%1).\nPlease check GuardianFile in option.ini.")
                             .arg(fileName));
        exit(0);
    }

    while(true)
    {
        QProcess::execute(fileName);
        qDebug()<<"file:"<<fileName<<" exit";
    }
    return a.exec();
}
