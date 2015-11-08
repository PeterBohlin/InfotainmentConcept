#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "navigationdialog.h"
#include "carsettingsdialog.h"

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
    void on_pushButtonNavigation_clicked();

    void on_pushButtonCarSettings_clicked();

private:
    void InitializeChildWindows();

    Ui::MainWindow *ui;    
    NavigationDialog* m_pNavigationDialog;
    CarSettingsDialog* m_pCarSettingsDialog;
};

#endif // MAINWINDOW_H
