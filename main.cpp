#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qss("./Resources/style/stylesheet.qss");

    if( qss.open(QFile::ReadOnly))//只读打开
    {
        qDebug("open success");
        QString style = QLatin1String(qss.readAll());//qss.readAll()是QByteArray类型
        a.setStyleSheet(style);
        qss.close();
    }else{
        qDebug("Open failed");
    }

    MainWindow w;
    w.show();
    return QCoreApplication::exec();
}
