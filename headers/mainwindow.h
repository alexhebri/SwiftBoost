#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_main_menu_clicked();
    void on_windows_tweaks_clicked();
    void on_cpu_tweaks_clicked();
    void on_gpu_tweaks_clicked();
    void on_network_clicked();
    void on_power_tweaks_clicked();
    void on_revert_and_services_clicked();

private:
    Ui::MainWindow *ui;
    QWidget *currentWidget;
    QButtonGroup *navButtons;

    void clearCurrentWidget();
};
#endif // MAINWINDOW_H
