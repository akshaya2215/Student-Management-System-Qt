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
}
void updatestudent::searchStudent()
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
            currentRow = row;

            ui->lineEditName->setText(studentTable->item(row,1)->text());
            ui->lineEditDept->setText(studentTable->item(row,2)->text());
            ui->lineEditYear->setText(studentTable->item(row,3)->text());
            ui->lineEditPhone->setText(studentTable->item(row,4)->text());

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

void updatestudent::updateStudent()
{
    if(currentRow == -1)
    {
        QMessageBox::warning(this,
                             "Error",
                             "Search a student first.");
        return;
    }

    studentTable->item(currentRow,1)->setText(ui->lineEditName->text());
    studentTable->item(currentRow,2)->setText(ui->lineEditDept->text());
    studentTable->item(currentRow,3)->setText(ui->lineEditYear->text());
    studentTable->item(currentRow,4)->setText(ui->lineEditPhone->text());

    QMessageBox::information(this,
                             "Success",
                             "Student Updated Successfully.");

    dashboard->show();

    this->close();
}

void updatestudent::back()
{
    dashboard->show();
    this->close();
}