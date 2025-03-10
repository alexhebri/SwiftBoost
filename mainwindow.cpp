#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "windowstweaks.h" // Include the header for WindowsTweaks
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
    myWidget->show(); myWidget->move(0,30);
}


void MainWindow::on_cpu_tweaks_clicked()
{

}

