#include "addstudent.h"
#include "ui_addstudent.h"
#include "management.h"
#include <QMessageBox>

addstudent::addstudent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addstudent)
{
    ui->setupUi(this);
studentTable = nullptr;
    connect(ui->pushButtonSave,
            SIGNAL(clicked()),
            this,
            SLOT(saveStudent()));

    connect(ui->pushButtonClear,
            SIGNAL(clicked()),
            this,
            SLOT(clearFields()));

    connect(ui->pushButtonBack,
            SIGNAL(clicked()),
            this,
            SLOT(back()));
}

addstudent::~addstudent()
{
    delete ui;
}
void addstudent::saveStudent()
{
    QString id = ui->lineEditID->text();
    QString name = ui->lineEditName->text();
    QString dept = ui->lineEditDept->text();
    QString year = ui->lineEditYear->text();
    QString phone = ui->lineEditPhone->text();

    if(id.isEmpty() || name.isEmpty() || dept.isEmpty()
        || year.isEmpty() || phone.isEmpty())
    {
        QMessageBox::warning(this,
                             "Error",
                             "Please fill all fields.");
        return;
    }

    if(studentTable != nullptr)
    {
        int row = studentTable->rowCount();

        studentTable->insertRow(row);

        studentTable->setItem(row,0,new QTableWidgetItem(id));
        studentTable->setItem(row,1,new QTableWidgetItem(name));
        studentTable->setItem(row,2,new QTableWidgetItem(dept));
        studentTable->setItem(row,3,new QTableWidgetItem(year));
        studentTable->setItem(row,4,new QTableWidgetItem(phone));
    }

    QMessageBox::information(this,
                             "Success",
                             "Student Added Successfully!");

    clearFields();
}
void addstudent::clearFields()
{
    ui->lineEditID->clear();
    ui->lineEditName->clear();
    ui->lineEditDept->clear();
    ui->lineEditYear->clear();
    ui->lineEditPhone->clear();
}
void addstudent::back()
{
    management *m = new management();

    m->show();

    this->close();
}
void addstudent::setTable(QTableWidget *table)
{
    studentTable = table;
}