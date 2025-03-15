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

private:
    Ui::gpu_tweaks *ui;
};

#endif // GPU_TWEAKS_H
