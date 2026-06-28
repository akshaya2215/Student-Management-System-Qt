#include "management.h"
#include "ui_management.h"
#include <QPixmap>
#include <QDebug>
#include "addstudent.h"
#include "searchstudent.h"
#include "updatestudent.h"
#include "deletestudent.h"
#include "mainwindow.h"
#include <QMessageBox>
management::management(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::management)
{
    ui->setupUi(this);

    connect(ui->pushButtonAdd,
            SIGNAL(clicked()),
            this,
            SLOT(addStudent()));
    connect(ui->pushButtonSearch,
            SIGNAL(clicked()),
            this,
            SLOT(searchStudent()));
    connect(ui->pushButtonUpdate,
            SIGNAL(clicked()),
            this,
            SLOT(updateStudent()));
    connect(ui->pushButtonDelete,
            SIGNAL(clicked()),
            this,
            SLOT(deleteStudent()));
    connect(ui->pushButtonLogout,
            SIGNAL(clicked()),
            this,
            SLOT(logout()));

}

management::~management()
{
    delete ui;
}
void management::addStudent()
{
    addstudent *student = new addstudent(this);

    student->setTable(ui->tableWidget);

    student->show();

    this->hide();
}
void management::searchStudent()
{
    searchstudent *s = new searchstudent(this);

    s->setTable(ui->tableWidget);

    s->show();

    this->hide();
}
void management::updateStudent()
{
    updatestudent *u = new updatestudent(this);

    u->setTable(ui->tableWidget);

    u->show();

    this->hide();
}
void management::deleteStudent()
{
    deletestudent *d = new deletestudent(this);

    d->setTable(ui->tableWidget);

    d->show();

    this->hide();
}
void management::logout()
{
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this,
                                  "Logout",
                                  "Are you sure you want to logout?",
                                  QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        MainWindow *login = new MainWindow();

        login->show();

        this->close();
    }
}