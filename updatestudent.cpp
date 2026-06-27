#include "updatestudent.h"
#include "ui_updatestudent.h"
#include "management.h"

#include <QMessageBox>

updatestudent::updatestudent(management *m, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::updatestudent)
{
    ui->setupUi(this);

    dashboard = m;
    studentTable = nullptr;
    currentRow = -1;

    connect(ui->pushButtonSearch,
            SIGNAL(clicked()),
            this,
            SLOT(searchStudent()));

    connect(ui->pushButtonUpdate,
            SIGNAL(clicked()),
            this,
            SLOT(updateStudent()));

    connect(ui->pushButtonBack,
            SIGNAL(clicked()),
            this,
            SLOT(back()));
}

updatestudent::~updatestudent()
{
    delete ui;
}

void updatestudent::setTable(QTableWidget *table)
{
    studentTable = table;
}void updatestudent::searchStudent()
{

}

void updatestudent::updateStudent()
{

}

void updatestudent::back()
{
    dashboard->show();
    this->close();
}