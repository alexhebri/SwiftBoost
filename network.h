#ifndef NETWORK_H
#define NETWORK_H

#include <QGroupBox>

namespace Ui {
class network;
}

class network : public QGroupBox
{
    Q_OBJECT

public:
    explicit network(QWidget *parent = nullptr);
    ~network();

private slots:
    void on_network_all_clicked();

    void on_network_throttling_clicked();

    void on_network_dynamic_clicked();

    void on_network_ping_clicked();

    void on_network_winsock_clicked();

    void on_bloatware_removal_clicked();

    void on_debloat_back_clicked();

    void on_debloat_data_clicked();

    void on_debloat_all_clicked();

    void on_clean_all_clicked();

    void on_clean_log_temp_clicked();

    void on_clean_cache_clicked();

private:
    Ui::network *ui;
};

#endif // NETWORK_H
