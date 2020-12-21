#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QSqlQuery>                //查询MySql的库
#include <QMessageBox>
#include <QCryptographicHash>       //包含MD5算法库

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    QString strToMd5(QString str);      //将密码转换为MD5加密
private slots:
    void on_loginPushButton_clicked();      //“登录”按钮单击事件槽
    void on_exitPushButton_clicked();       //“退出”按钮单击事件槽

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
