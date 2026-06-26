#ifndef SEARCHSTUDENT_H
#define SEARCHSTUDENT_H

#include <QWidget>
#include <QTableWidget>

namespace Ui {
class searchstudent;
}

class searchstudent : public QWidget
{
    Q_OBJECT

public:
    explicit searchstudent(QWidget *parent = nullptr);
    ~searchstudent();

    void setTable(QTableWidget *table);

private slots:
    void searchStudent();

private:
    Ui::searchstudent *ui;

    QTableWidget *studentTable;
};

#endif