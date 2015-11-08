#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),m_pNavigationDialog(nullptr), m_pCarSettingsDialog(nullptr)
{
    ui->setupUi(this);
    InitializeChildWindows();
    QPalette* palette = new QPalette();
    QPixmap * pixmap = new QPixmap(":/images/xc60dash.jpg");
    int iWidth = this->width();
    int iHeight = this->height();
    palette->setBrush(QPalette::Window,*(new QBrush((pixmap->scaled(iWidth, iHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation)))));
    setPalette(*palette);
    //setWindowFlags(Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitializeChildWindows()
{
    m_pNavigationDialog = new NavigationDialog(this);
    m_pCarSettingsDialog = new CarSettingsDialog(this);
}

void MainWindow::on_pushButtonNavigation_clicked()
{
    if(m_pNavigationDialog != nullptr)
    {
        m_pNavigationDialog->setModal(true);
        m_pNavigationDialog->show();
    }
}

void MainWindow::on_pushButtonCarSettings_clicked()
{
    if(m_pCarSettingsDialog != nullptr)
    {
        m_pCarSettingsDialog->setModal(true);
        m_pCarSettingsDialog->show();
    }
}
