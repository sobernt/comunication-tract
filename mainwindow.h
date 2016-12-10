#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_checkBox_toggled(bool checked);
    void calculate();
    void calculateRmax();
    void on_h1_valueChanged();

    void on_h2_valueChanged();

    void on_f_valueChanged();

    void on_p1_valueChanged();

    void on_d1_valueChanged();

    void on_d2_valueChanged();

    void on_r_valueChanged();

    void on_F_valueChanged();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
