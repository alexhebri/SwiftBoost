#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "cpu_tweaks.h"
#include "network.h"
#include "power_tweaks.h"
#include "windowstweaks.h"
#include "gpu_tweaks.h"
#include "revert_and_services.h"
#include "mainmenu.h"


#include <QWidget>
#include <QGroupBox>
#include <QFile>
#include <QIcon>
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("SwiftBoost");

    QIcon windowIcon("C:/Users/Alex/Desktop/Optimization_Program-UI/logo_1.png");
    setWindowIcon(windowIcon);

    mainmenu *myWidget = new mainmenu(this);

    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_mainmenu");
    if (groupBox) {
        groupBox->setTitle("Main Menu");
    }

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(myWidget);
    setLayout(layout);
    myWidget->show(); myWidget->move(0,39);

    //ui->group_mainmenu->setVisible(true);
}




MainWindow::~MainWindow()
{
    delete ui;
    //ui->group_windows->setVisible(true);
}


void MainWindow::on_main_menu_clicked()
{
    //ui->group_windows->setVisible(true);
    mainmenu *myWidget = new mainmenu(this);


    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_mainmenu");
    if (groupBox) {
        groupBox->setTitle("Main Menu");
    }


    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(myWidget);
    setLayout(layout);
    myWidget->show(); myWidget->move(0,39);
}

void MainWindow::on_windows_tweaks_clicked()
{

    windowstweaks *myWidget = new windowstweaks(this);


    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_windows");
    if (groupBox) {
        groupBox->setTitle("Windows Tweaks");
    }


    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(myWidget);
    setLayout(layout);
    myWidget->show(); myWidget->move(0,39);
}


void MainWindow::on_cpu_tweaks_clicked()
{
    cpu_tweaks *myWidget = new cpu_tweaks(this);

    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_cpu");
    if (groupBox) {
        groupBox->setTitle("CPU Tweaks");
    }

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(myWidget);
    setLayout(layout);
    myWidget->show(); myWidget->move(0,39);

}


void MainWindow::on_gpu_tweaks_clicked()
{
    gpu_tweaks *myWidget = new gpu_tweaks(this);

    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_gpu");
    if (groupBox) {
        groupBox->setTitle("GPU Tweaks");
    }

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(myWidget);
    setLayout(layout);
    myWidget->show(); myWidget->move(0,39);
}


void MainWindow::on_network_clicked()
{
    network *myWidget = new network(this);

    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_network");
    if (groupBox) {
        groupBox->setTitle("Network Tweaks");
    }

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(myWidget);
    setLayout(layout);
    myWidget->show(); myWidget->move(0,39);
}


void MainWindow::on_power_tweaks_clicked()
{
    power_tweaks *myWidget = new power_tweaks(this);

    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_power");
    if (groupBox) {
        groupBox->setTitle("Power Tweaks");
    }

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(myWidget);
    setLayout(layout);
    myWidget->show(); myWidget->move(0,39);
}


void MainWindow::on_revert_and_services_clicked()
{
    revert_and_services *myWidget = new revert_and_services(this);

    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_revert_and_services");
    if (groupBox) {
        groupBox->setTitle("Revert and Services");
    }

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(myWidget);
    setLayout(layout);
    myWidget->show(); myWidget->move(0,39);
}

