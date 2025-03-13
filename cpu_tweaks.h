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

private:
    Ui::cpu_tweaks *ui;
};

#endif // CPU_TWEAKS_H
