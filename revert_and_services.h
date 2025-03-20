#ifndef REVERT_AND_SERVICES_H
#define REVERT_AND_SERVICES_H

#include <QGroupBox>

namespace Ui {
class revert_and_services;
}

class revert_and_services : public QGroupBox
{
    Q_OBJECT

public:
    explicit revert_and_services(QWidget *parent = nullptr);
    ~revert_and_services();

private:
    Ui::revert_and_services *ui;
};

#endif // REVERT_AND_SERVICES_H
