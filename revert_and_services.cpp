#include "revert_and_services.h"
#include "ui_revert_and_services.h"

revert_and_services::revert_and_services(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::revert_and_services)
{
    ui->setupUi(this);
}

revert_and_services::~revert_and_services()
{
    delete ui;
}
