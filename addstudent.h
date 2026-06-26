#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H
#include <QTableWidget>

#include <QWidget>

namespace Ui {
class addstudent;
}

class addstudent : public QWidget
{
    Q_OBJECT

public:
    explicit addstudent(QWidget *parent = nullptr);
    ~addstudent();
    void setTable(QTableWidget *table);
private slots:
    void saveStudent();
    void clearFields();
    void back();

private:
    Ui::addstudent *ui;
    QTableWidget *studentTable;
};

#endif // ADDSTUDENT_H
