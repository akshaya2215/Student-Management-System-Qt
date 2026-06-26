#include "searchstudent.h"
#include "ui_searchstudent.h"
#include <QMessageBox>

searchstudent::searchstudent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::searchstudent)
{
    ui->setupUi(this);

    studentTable = nullptr;

    connect(ui->pushButtonSearch,
            SIGNAL(clicked()),
            this,
            SLOT(searchStudent()));
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
        if(studentTable->item(row,0)->text() == id)
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