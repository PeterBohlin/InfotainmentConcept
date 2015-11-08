#ifndef CARSETTINGSDIALOG_H
#define CARSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class CarSettingsDialog;
}

class CarSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CarSettingsDialog(QWidget *parent = 0);
    ~CarSettingsDialog();

private:
    Ui::CarSettingsDialog *ui;
};

#endif // CARSETTINGSDIALOG_H
