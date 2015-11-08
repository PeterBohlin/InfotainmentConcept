#include "navigationdialog.h"
#include "ui_navigationdialog.h"

NavigationDialog::NavigationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NavigationDialog)
{
    ui->setupUi(this);
    ui->webViewNavigation->load(QUrl("http://www.volvocars.com/intl"));
}

NavigationDialog::~NavigationDialog()
{
    delete ui;
}
