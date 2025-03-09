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

private:
    Ui::windowstweaks *ui;
};

#endif // WINDOWSTWEAKS_H
