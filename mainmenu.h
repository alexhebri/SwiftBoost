#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGroupBox>

namespace Ui {
class mainmenu;
}

class mainmenu : public QGroupBox
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

private:
    Ui::mainmenu *ui;
};

#endif // MAINMENU_H
