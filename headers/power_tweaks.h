#ifndef POWER_TWEAKS_H
#define POWER_TWEAKS_H

#include <QGroupBox>

namespace Ui {
class power_tweaks;
}

class power_tweaks : public QGroupBox
{
    Q_OBJECT

public:
    explicit power_tweaks(QWidget *parent = nullptr);
    ~power_tweaks();

private slots:
    void on_plan_ultimate_clicked();

    void on_plan_high_clicked();

    void on_extra_performance_clicked();

    void on_disable_cpupark_clicked();

    void on_gpu_Max_clicked();

    void on_mmcss_clicked();

    void on_disable_powerthrottling_clicked();

    void on_disable_sleep_clicked();

    void on_disable_fullscreenglobally_clicked();

    void on_disable_automaint_clicked();

    void on_run_ultimate_clicked();

    void on_run_high_clicked();

private:
    Ui::power_tweaks *ui;
};

#endif // POWER_TWEAKS_H
