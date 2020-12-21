#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setFixedSize(400 ,300);         //登录对话框固定大小
    ui->pwdLineEdit->setFocus();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginPushButton_clicked()
{
    if(!ui->pwdLineEdit->text().isEmpty())
    {
        QSqlQuery query;
        query.exec("select Password from member where MemberID='" + ui->adminLineEdit->text() + "'");       //从数据库中查询纯口令密码字段
        query.next();
        QString pwdMd5 = strToMd5(ui->pwdLineEdit->text());
        if(query.value(0).toString() == pwdMd5)
        {
            QDialog::accept();      //验证通过
        }
        else{
            QMessageBox::warning(this,tr("口令错误"),tr("请输入正确的命令！"),QMessageBox::Ok);
            ui->pwdLineEdit->clear();
            ui->pwdLineEdit->setFocus();
        }
    }else{
        ui->pwdLineEdit->setFocus();
    }
}

void LoginDialog::on_exitPushButton_clicked()
{
    QDialog::reject();
}

QString LoginDialog::strToMd5(QString str)
{
    QString StrMd5;
    QByteArray qba;
    qba = QCryptographicHash::hash(str.toLatin1(),  QCryptographicHash::Md5);

    StrMd5.append(qba.toHex());
    return StrMd5;
}
