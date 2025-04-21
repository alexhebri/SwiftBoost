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

    QIcon windowIcon(":/images/logo_1.png");
    this->setWindowIcon(windowIcon);


    setWindowIcon(windowIcon);

    mainmenu *myWidget = new mainmenu(this);

    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_mainmenu");
    if (groupBox) {
        groupBox->setTitle("Main Menu");
    }

    ui->main_menu->setStyleSheet("background-color: rgb(46, 139, 87); color: black;");
    ui->windows_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->cpu_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->gpu_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->power_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->network->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->revert_and_services->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");


    QLayout* layout = ui->group_windows->layout();
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->setParent(nullptr);
                delete item->widget();
            }
            delete item;
        }
        layout->addWidget(myWidget);
    }
    myWidget->show();
    myWidget->move(0, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_main_menu_clicked()
{
    ui->main_menu->setStyleSheet("background-color: rgb(46, 139, 87); color: black;");
    ui->windows_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->cpu_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->gpu_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->power_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->network->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->revert_and_services->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");

    mainmenu *myWidget = new mainmenu(this);

    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_mainmenu");
    if (groupBox) {
        groupBox->setTitle("Main Menu");
    }

    QLayout* layout = ui->group_windows->layout();
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->setParent(nullptr);
                delete item->widget();
            }
            delete item;
        }
        layout->addWidget(myWidget);
    }

    myWidget->show();
    myWidget->move(0, 0);
}

void MainWindow::on_windows_tweaks_clicked()
{
    ui->main_menu->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->windows_tweaks->setStyleSheet("background-color: rgb(46, 139, 87); color: black;");
    ui->cpu_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->gpu_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->power_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->network->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->revert_and_services->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");

    windowstweaks *myWidget = new windowstweaks(this);

    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_windows");
    if (groupBox) {
        groupBox->setTitle("Windows Tweaks");
    }

    QLayout* layout = ui->group_windows->layout();
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->setParent(nullptr);
                delete item->widget();
            }
            delete item;
        }
        layout->addWidget(myWidget);
    }

    myWidget->show();
    myWidget->move(0, 0);
}

void MainWindow::on_cpu_tweaks_clicked()
{

    ui->main_menu->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->windows_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->cpu_tweaks->setStyleSheet("background-color: rgb(46, 139, 87); color: black;");
    ui->gpu_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->power_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->network->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->revert_and_services->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");

    cpu_tweaks *myWidget = new cpu_tweaks(this);

    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_cpu");
    if (groupBox) {
        groupBox->setTitle("CPU Tweaks");
    }


    QLayout* layout = ui->group_windows->layout();
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->setParent(nullptr);
                delete item->widget();
            }
            delete item;
        }
        layout->addWidget(myWidget);
    }

    myWidget->show();
    myWidget->move(0, 0);
}

void MainWindow::on_gpu_tweaks_clicked()
{

    ui->main_menu->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->windows_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->cpu_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->gpu_tweaks->setStyleSheet("background-color: rgb(46, 139, 87); color: black;");
    ui->power_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->network->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->revert_and_services->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");

    gpu_tweaks *myWidget = new gpu_tweaks(this);

    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_gpu");
    if (groupBox) {
        groupBox->setTitle("GPU Tweaks");
    }


    QLayout* layout = ui->group_windows->layout();
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->setParent(nullptr);
                delete item->widget();
            }
            delete item;
        }
        layout->addWidget(myWidget);
    }

    myWidget->show();
    myWidget->move(0, 0);
}

void MainWindow::on_network_clicked()
{

    ui->main_menu->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->windows_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->cpu_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->gpu_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->power_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->network->setStyleSheet("background-color: rgb(46, 139, 87); color: black;");
    ui->revert_and_services->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");

    network *myWidget = new network(this);

    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_network");
    if (groupBox) {
        groupBox->setTitle("Network Tweaks");
    }


    QLayout* layout = ui->group_windows->layout();
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->setParent(nullptr);
                delete item->widget();
            }
            delete item;
        }
        layout->addWidget(myWidget);
    }

    myWidget->show();
    myWidget->move(0, 0);
}

void MainWindow::on_power_tweaks_clicked()
{

    ui->main_menu->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->windows_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->cpu_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->gpu_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->power_tweaks->setStyleSheet("background-color: rgb(46, 139, 87); color: black;");
    ui->network->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->revert_and_services->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");

    power_tweaks *myWidget = new power_tweaks(this);

    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_power");
    if (groupBox) {
        groupBox->setTitle("Power Tweaks");
    }


    QLayout* layout = ui->group_windows->layout();
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->setParent(nullptr);
                delete item->widget();
            }
            delete item;
        }
        layout->addWidget(myWidget);
    }

    myWidget->show();
    myWidget->move(0, 0);
}

void MainWindow::on_revert_and_services_clicked()
{

    ui->main_menu->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->windows_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->cpu_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->gpu_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->power_tweaks->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->network->setStyleSheet("background-color: rgb(58, 79, 80); color: white;");
    ui->revert_and_services->setStyleSheet("background-color: rgb(46, 139, 87); color: black;");

    revert_and_services *myWidget = new revert_and_services(this);

    QGroupBox* groupBox = myWidget->findChild<QGroupBox*>("group_revert_and_services");
    if (groupBox) {
        groupBox->setTitle("Revert and Services");
    }


    QLayout* layout = ui->group_windows->layout();
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->setParent(nullptr);
                delete item->widget();
            }
            delete item;
        }
        layout->addWidget(myWidget);
    }

    myWidget->show();
    myWidget->move(0, 0);
}
