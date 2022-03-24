#ifndef TRANCEPARANCY_H
#define TRANCEPARANCY_H

#include <QDialog>
#include <QScrollBar>

namespace Ui {
class Tranceparancy;
}

class Tranceparancy : public QDialog
{
    Q_OBJECT

public:
    explicit Tranceparancy(QWidget *parent = nullptr);
    ~Tranceparancy();

    double value=0;
    QScrollBar *scrollbar;

private slots:
    void on_pushButton_ok_pressed();

    void on_horizontalScrollBar_sliderMoved(int position);

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Tranceparancy *ui;
};

#endif // TRANCEPARANCY_H
