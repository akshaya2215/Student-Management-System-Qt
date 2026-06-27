#ifndef UPDATESTUDENT_H
#define UPDATESTUDENT_H

#include <QWidget>
#include <QTableWidget>

class management;

namespace Ui {
class updatestudent;
}

class updatestudent : public QWidget
{
    Q_OBJECT

public:
    explicit updatestudent(management *m, QWidget *parent = nullptr);
    ~updatestudent();

    void setTable(QTableWidget *table);

private slots:
    void searchStudent();
    void updateStudent();
    void back();

private:
    Ui::updatestudent *ui;

    QTableWidget *studentTable;
    management *dashboard;

    int currentRow;
};

#endif // UPDATESTUDENT_H