#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include "management.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(button()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(exit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button()
{
    QString name[]={"abc","def","ghi"};//registered names
    QString code[]={"abc12","def34","ghi56"};//registered password
    QString uName = ui->lineEdit_2->text();
    QString uCode = ui->lineEdit_5->text();
    bool found=false;
    for(int i=0;i<name->length();i++){
        if(uName == name[i] && uCode== code[i]){
            QMessageBox::information(this,"Welcome Message",
                  "User: "+name[i]+"\n"
                                                          "you have successfully logined to Management System");
            management *m = new management();
            m->show();

            this->hide();      // Hide the login window
            found = true;
            break;
        }
    }
    if(!found){
            QMessageBox::information(this,"ERROR",
                                     "Invalid username or password ");
        }
}


void MainWindow::exit()
{
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this,
                                  "Exit",
                                  "Are you sure you want to exit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}

