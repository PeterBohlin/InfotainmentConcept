#include "carsettingsdialog.h"
#include "ui_carsettingsdialog.h"
#include <QFile>
#include <QTextStream>

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

void CarSettingsDialog::DisplayDialog()
{
    LoadSettings();
    show();
}

void CarSettingsDialog::on_buttonBox_accepted()
{
    StoreSettings();
}

void CarSettingsDialog::LoadSettings()
{
    QFile file("settings.dat");
    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);
        qint32 iSteer = 1;
        qint32 iThrottle = 1;
        qint32 iGear = 1;
        qint32 iDamp = 1;

        if(!in.atEnd())
            in >> iSteer;
        if(!in.atEnd())
            in >> iThrottle;
        if(!in.atEnd())
            in >> iGear;
        if(!in.atEnd())
            in >> iDamp;

        file.close();

        ui->horizontalSliderSteering->setValue(iSteer);
        ui->horizontalSliderThrottle->setValue(iThrottle);
        ui->horizontalSliderShift->setValue(iGear);
        ui->horizontalSliderDamper->setValue(iDamp);
    }
    else
    {
        // Error...
    }
}

void CarSettingsDialog::StoreSettings()
{
    QFile file("settings.dat");
    if (!file.open(QIODevice::OpenModeFlag::WriteOnly))
        return;

    CarSettings settings(ui->horizontalSliderSteering->value(), ui->horizontalSliderThrottle->value(), ui->horizontalSliderShift->value(), ui->horizontalSliderDamper->value());

    QDataStream outstream(&file);

    outstream << (qint32)settings.GetSteeringValue();
    outstream << (qint32)settings.GetThrottleValue();
    outstream << (qint32)settings.GetGearingValue();
    outstream << (qint32)settings.GetDampeningValue();

    file.close();
}
