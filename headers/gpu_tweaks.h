#ifndef GPU_TWEAKS_H
#define GPU_TWEAKS_H

#include <QGroupBox>

namespace Ui {
class gpu_tweaks;
}

class gpu_tweaks : public QGroupBox
{
    Q_OBJECT

public:
    explicit gpu_tweaks(QWidget *parent = nullptr);
    ~gpu_tweaks();

private slots:

    void on_nvidia_reg_clicked();

    void on_nvidia_advanced_clicked();

    void on_amd_all_clicked();

    void on_amd_reg_clicked();

    void on_amd_boost_clicked();

    void on_amd_radeon_clicked();

    void on_amd_ultralow_clicked();

    void on_latency_and_render_clicked();

    void on_nvidia_clicked();

    void on_nvidia_telemety_clicked();

private:
    Ui::gpu_tweaks *ui;
};

#endif // GPU_TWEAKS_H
