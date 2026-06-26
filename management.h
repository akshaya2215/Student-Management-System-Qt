#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <QWidget>

namespace Ui {
class management;
}

class management : public QWidget
{
    Q_OBJECT

public:
    explicit management(QWidget *parent = nullptr);
    ~management();

private:
    Ui::management *ui;
private slots:
    void addStudent();
    void searchStudent();

};

#endif // MANAGEMENT_H
