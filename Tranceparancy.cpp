#include "Tranceparancy.h"
#include "ui_Tranceparancy.h"

Tranceparancy::Tranceparancy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tranceparancy)
{
    ui->setupUi(this);

    //! Connect visa versa.
    QObject::connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged),ui->horizontalScrollBar, &QScrollBar::setValue);
    QObject::connect(ui->horizontalScrollBar, QOverload<int>::of(&QScrollBar::valueChanged), ui->spinBox, &QSpinBox::setValue);

    value=ui->horizontalScrollBar->value();
    scrollbar=ui->horizontalScrollBar;
    ui->spinBox->setValue(value);
}

Tranceparancy::~Tranceparancy()
{
    delete ui;
}

void Tranceparancy::on_pushButton_ok_pressed()
{
    value=ui->horizontalScrollBar->value();
    this->close();
}

void Tranceparancy::on_horizontalScrollBar_sliderMoved(int position)
{
    value=ui->horizontalScrollBar->value();
}

void Tranceparancy::on_spinBox_valueChanged(int arg1)
{
    value=ui->horizontalScrollBar->value();
}
