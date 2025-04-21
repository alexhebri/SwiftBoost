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

private slots:

    void on_textBrowser_copyAvailable(bool b);

    void on_pushButton_clicked();

private:
    Ui::mainmenu *ui;
};

#endif // MAINMENU_H
