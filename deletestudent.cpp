#include "deletestudent.h"
#include "ui_deletestudent.h"
#include "management.h"

#include <QMessageBox>

deletestudent::deletestudent(management *m, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::deletestudent)
{
    ui->setupUi(this);

    dashboard = m;
    studentTable = nullptr;
    currentRow = -1;

    connect(ui->pushButtonSearch,
            SIGNAL(clicked()),
            this,
            SLOT(searchStudent()));

    connect(ui->pushButtonDelete,
            SIGNAL(clicked()),
            this,
            SLOT(deleteStudent()));

    connect(ui->pushButtonBack,
            SIGNAL(clicked()),
            this,
            SLOT(back()));
}

deletestudent::~deletestudent()
{
    delete ui;
}

void deletestudent::setTable(QTableWidget *table)
{
    studentTable = table;
}
void deletestudent::searchStudent()
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
void deletestudent::deleteStudent()
{
    if(currentRow == -1)
    {
        QMessageBox::warning(this,
                             "Error",
                             "Search a student first.");
        return;
    }

    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this,
                                  "Delete",
                                  "Are you sure you want to delete this student?",
                                  QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        studentTable->removeRow(currentRow);

        QMessageBox::information(this,
                                 "Success",
                                 "Student deleted successfully.");

        dashboard->show();
        this->close();
    }
}
void deletestudent::back()
{
    dashboard->show();
    this->close();
}
