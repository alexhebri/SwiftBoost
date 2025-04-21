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

    void on_windows_update_clicked();

    void on_disable_findmydevice_clicked();

    void on_disable_transparency_clicked();

    void on_disable_loc_not_hgr_clicked();

    void on_disable_game_cort_sync_clicked();

    void on_enable_game_hardacc_clicked();

    void on_disable_keys_narr_magn_clicked();

    void on_disable_telemetry_and_data_clicked();

    void on_disable_onedrive_unnapps_clicked();

    void on_priority_and_mouse_keyboard_clicked();

    void on_run_all_clicked();

private:
    Ui::windowstweaks *ui;
};

#endif // WINDOWSTWEAKS_H
