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

private:
    Ui::windowstweaks *ui;
};

#endif // WINDOWSTWEAKS_H
