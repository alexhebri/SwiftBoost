#ifndef WINDOWSTWEAKS_H
#define WINDOWSTWEAKS_H

#include <QGroupBox>

namespace Ui {
class windowstweaks;
}

class windowstweaks : public QGroupBox
{
    Q_OBJECT

public:
    explicit windowstweaks(QWidget *parent = nullptr);
    ~windowstweaks();

private slots:
    void on_restore_point_clicked();

    void on_disable_uac_clicked();

    void on_pushButton_4_clicked();

    void on_windows_update_clicked();

    void on_windwos_update_clicked();

    void on_disable_findmydevice_clicked();

private:
    Ui::windowstweaks *ui;
};

#endif // WINDOWSTWEAKS_H
