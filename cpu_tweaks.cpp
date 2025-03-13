#include "cpu_tweaks.h"
#include "ui_cpu_tweaks.h"

cpu_tweaks::cpu_tweaks(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::cpu_tweaks)
{
    ui->setupUi(this);
}

cpu_tweaks::~cpu_tweaks()
{
    delete ui;
}
