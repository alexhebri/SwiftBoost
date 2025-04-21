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

private slots:
    void on_disable_unwanted_clicked();

    void on_disable_unnecessary_clicked();

    void on_disable_telemetry_clicked();

    void on_disable_bluetooth_clicked();

    void on_disable_xbox_clicked();

    void on_disable_printer_clicked();

    void on_disable_updates_clicked();

    void on_disable_notifications_clicked();

    void on_disable_transparency_clicked();

    void on_disable_findmydevice_clicked();

    void on_disable_power_throttling_clicked();

    void on_enable_bluetooth_clicked();

    void on_enable_xbox_clicked();

    void on_enable_printer_clicked();

    void on_enable_updates_clicked();

    void on_enable_notifications_clicked();

    void on_enable_transparency_clicked();

    void on_enable_findmydevice_clicked();

    void on_enable_power_throttling_clicked();

private:
    Ui::revert_and_services *ui;
};

#endif // REVERT_AND_SERVICES_H
