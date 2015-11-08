#ifndef NAVIGATIONDIALOG_H
#define NAVIGATIONDIALOG_H

#include <QDialog>

namespace Ui {
class NavigationDialog;
}

class NavigationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NavigationDialog(QWidget *parent = 0);
    ~NavigationDialog();

private:
    Ui::NavigationDialog *ui;
};

#endif // NAVIGATIONDIALOG_H
