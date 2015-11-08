#include "carsettingsdialog.h"
#include "ui_carsettingsdialog.h"

CarSettingsDialog::CarSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarSettingsDialog)
{
    ui->setupUi(this);
    QPalette* palette = new QPalette();
    QPixmap * pixmap = new QPixmap(":/images/xc90seats.jpg");
    int iWidth = this->width();
    int iHeight = this->height();
    palette->setBrush(QPalette::Window,*(new QBrush((pixmap->scaled(iWidth, iHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation)))));
    setPalette(*palette);
}

CarSettingsDialog::~CarSettingsDialog()
{
    delete ui;
}
