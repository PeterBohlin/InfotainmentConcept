#include "carsettingsdialog.h"
#include "ui_carsettingsdialog.h"

CarSettingsDialog::CarSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarSettingsDialog)
{
    ui->setupUi(this);    
}

CarSettingsDialog::~CarSettingsDialog()
{
    delete ui;
}
