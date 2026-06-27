#include "searchstudent.h"
#include "ui_searchstudent.h"
#include "management.h"
#include <QMessageBox>

searchstudent::searchstudent(management *m, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::searchstudent)
{
    ui->setupUi(this);

    dashboard = m;
    studentTable = nullptr;

    connect(ui->pushButtonSearch,
            SIGNAL(clicked()),
            this,
            SLOT(searchStudent()));

    connect(ui->pushButtonBack,
            SIGNAL(clicked()),
            this,
            SLOT(back()));
}
void searchstudent::setTable(QTableWidget *table)
{
    studentTable = table;
}
searchstudent::~searchstudent()
{
    delete ui;
}
void searchstudent::searchStudent()
{
    if(studentTable == nullptr)
    {
        QMessageBox::warning(this,
                             "Error",
                             "Table not available.");
        return;
    }

    QString id = ui->lineEditID->text();

    bool found = false;

    for(int row = 0; row < studentTable->rowCount(); row++)
    {

        QTableWidgetItem *item = studentTable->item(row,0);

        if(item && item->text() == id)
        {
            ui->labelName->setText(studentTable->item(row,1)->text());
            ui->labelDept->setText(studentTable->item(row,2)->text());
            ui->labelYear->setText(studentTable->item(row,3)->text());
            ui->labelPhone->setText(studentTable->item(row,4)->text());

            found = true;
            break;
        }
    }

    if(!found)
    {
        QMessageBox::warning(this,
                             "Not Found",
                             "Student not found.");
    }
}
void searchstudent::back()
{
    dashboard->show();
    this->close();
}