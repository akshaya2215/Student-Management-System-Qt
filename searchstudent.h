#ifndef SEARCHSTUDENT_H
#define SEARCHSTUDENT_H

#include <QWidget>
#include <QTableWidget>
class management;
namespace Ui {
class searchstudent;
}

class searchstudent : public QWidget
{
    Q_OBJECT

public:
    explicit searchstudent(management *m, QWidget *parent = nullptr);
    ~searchstudent();

    void setTable(QTableWidget *table);

private slots:
    void searchStudent();
    void back();

private:
    Ui::searchstudent *ui;

    QTableWidget *studentTable;
     management *dashboard;
};

#endif