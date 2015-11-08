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
    void DisplayDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CarSettingsDialog *ui;
    void StoreSettings();
    void LoadSettings();

    class CarSettings
    {
    public:

        CarSettings():m_iSteeringValue(0), m_iThrottleValue(0), m_iGearValue(0), m_iDampeningValue(0){}

        CarSettings(int iSteeringValue, int iThrottleValue, int iGearValue, int iDampeningValue)
            :m_iSteeringValue(iSteeringValue), m_iThrottleValue(iThrottleValue), m_iGearValue(iGearValue), m_iDampeningValue(iDampeningValue){}

        void SerializeToStream();
        void SerializeFromStream();
        int GetSteeringValue(){ return m_iSteeringValue;}
        int GetThrottleValue(){ return m_iThrottleValue;}
        int GetGearingValue(){ return m_iGearValue;}
        int GetDampeningValue(){ return m_iDampeningValue;}

    private:
        int m_iSteeringValue;
        int m_iThrottleValue;
        int m_iGearValue;
        int m_iDampeningValue;
    };
};

#endif // CARSETTINGSDIALOG_H
