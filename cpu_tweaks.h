#ifndef CPU_TWEAKS_H
#define CPU_TWEAKS_H

#include <QGroupBox>

namespace Ui {
class cpu_tweaks;
}

class cpu_tweaks : public QGroupBox
{
    Q_OBJECT

public:
    explicit cpu_tweaks(QWidget *parent = nullptr);
    ~cpu_tweaks();

private slots:
    void on_cpu_runall_clicked();

    void on_cpu_general_clicked();

    void on_cpu_responsiveness_clicked();

    void on_cpu_intel_clicked();

    void on_cpu_amd_clicked();

    void on_disable_idle_clicked();

    void on_enable_idle_clicked();

    void on_multimedia_scheduling_clicked();

    void on_disable_core_parking_clicked();

private:
    Ui::cpu_tweaks *ui;
};

#endif // CPU_TWEAKS_H
