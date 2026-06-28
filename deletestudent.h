#ifndef DELETESTUDENT_H
#define DELETESTUDENT_H

#include <QWidget>
#include <QTableWidget>

class management;

namespace Ui {
class deletestudent;
}

class deletestudent : public QWidget
{
    Q_OBJECT

public:
    explicit deletestudent(management *m, QWidget *parent = nullptr);
    ~deletestudent();

    void setTable(QTableWidget *table);

private slots:
    void searchStudent();
    void deleteStudent();
    void back();

private:
    Ui::deletestudent *ui;

    QTableWidget *studentTable;
    management *dashboard;

    int currentRow;
};

#endif // DELETESTUDENT_H