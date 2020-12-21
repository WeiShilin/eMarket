#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <QProcess>                     //Qt进程模块

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!createMySqlConn())
    {
        //若初次尝试连接不成功，就用代码方式启动MySql服务进程
        QProcess process;
        process.start("C:/Program Files/MySQL/MySQL Server 8.0/bin/mysqld.exe");
        //第二次尝试连接
        if(!createMyAqlConn()) return 1 ;
    }
    LoginDialog logindlg;
    if(logoindlg.exec() == QDialog::Accepted)
    {
        MainWindow w;
        w.show();           //启动主窗体
        return a.exec();
    } else{
        return 0;
    }

}
