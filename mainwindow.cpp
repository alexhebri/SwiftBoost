#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "cpu_tweaks.h"
#include "windowstweaks.h"


#include <QWidget>
#include <QGroupBox>
#include <QFile>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->group_windows->setVisible(false);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_main_menu_clicked()
{
    ui->group_windows->setVisible(false);
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

