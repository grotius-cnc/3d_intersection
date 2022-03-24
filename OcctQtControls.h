#ifndef OCCTQTCONTROLS_H
#define OCCTQTCONTROLS_H

#include <QWidget>
#include <QLabel>
#include <QToolButton>
#include <QSlider>

namespace Ui {
class OcctQtControls;
}

class OcctQtControls : public QWidget
{
    Q_OBJECT

public:
    explicit OcctQtControls(QWidget *parent = nullptr);
    ~OcctQtControls();

    QLabel *lbl_x,*lbl_y,*lbl_z;
    QToolButton *btn_zoom_top, *btn_zoom_bottom, *btn_zoom_front, *btn_zoom_back, *btn_zoom_left, *btn_zoom_right, *btn_zoom_extends, *btn_zoom_plus, *btn_zoom_min, *btn_zoom_3d;

signals:
    void toolButton_intersect_pressed();
    void toolButton_spline_line_pressed();

private slots:

    void on_toolButton_intersect_pressed();

    void on_toolButton_spline_line_pressed();

private:
    Ui::OcctQtControls *ui;
};

#endif // OCCTQTCONTROLS_H
