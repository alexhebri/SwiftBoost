#include "gpu_tweaks.h"
#include "ui_gpu_tweaks.h"

gpu_tweaks::gpu_tweaks(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::gpu_tweaks)
{
    ui->setupUi(this);
}

gpu_tweaks::~gpu_tweaks()
{
    delete ui;
}
