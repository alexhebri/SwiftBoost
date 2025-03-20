#include "network.h"
#include "ui_network.h"

network::network(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::network)
{
    ui->setupUi(this);
}

network::~network()
{
    delete ui;
}

void network::on_network_all_clicked()
{

}

