#include "windowstweaks.h"
#include "ui_windowstweaks.h"

windowstweaks::windowstweaks(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::windowstweaks)
{
    ui->setupUi(this);
}

windowstweaks::~windowstweaks()
{
    delete ui;
}

void windowstweaks::on_restore_point_clicked()
{

}

