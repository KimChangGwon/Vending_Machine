#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>
using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = NULL);
    int money_;
    ~Widget();
    void setControler(void);

private slots:
    void on_PB100_clicked();

    void on_PB500_2_clicked();

    void on_PB50_clicked();

    void on_PB10_clicked();

    void on_pbCoffe_clicked();

    void on_pbTea_clicked();

    void on_pbCola_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
