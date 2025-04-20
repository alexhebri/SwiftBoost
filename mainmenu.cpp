#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <windows.h>
#include <QSysInfo>
#include <QStorageInfo>
#include <QTextStream>
#include <QTextBrowser>
#include <QGroupBox>

#include <dxgi.h>
#pragma comment(lib, "dxgi.lib")

#include <QDesktopServices>
#include <QUrl>

QString getCPUName();
QString getGPUInfoLabeled();
QString getRAMInfo();
QString getDiskInfo();
QString getOSInfo();
QString getWindowsType();
QString getSystemRating();

mainmenu::mainmenu(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::mainmenu)
{
    ui->setupUi(this);
    ui->label_logo->setScaledContents(true);
    ui->label_logo->setPixmap(QPixmap(":/images/logo_1.png").scaled(
        ui->label_logo->width(),
        ui->label_logo->height(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation));
    QApplication::setWindowIcon(QIcon(":/images/logo_1.png"));


    /*
    ui->textBrowser_info->setStyleSheet(R"(
    QTextBrowser {
        background-color: #111111;
        color: #c8c8c8;
        border: none;
        padding: 10px;
        font: 12px 'Segoe UI';
    }
)");

    QString info;
    QTextStream stream(&info);


    info += "🧠  <b>CPU:</b> " + getCPUName() + "<br>";
    info += "🎮  <b>GPU:</b> " + getGPUInfoLabeled().replace("\n", "<br>&nbsp;&nbsp;&nbsp;&nbsp;") + "<br>";
    info += "💾  <b>RAM:</b> " + getRAMInfo() + "<br>";
    info += "💽  <b>Disk:</b> " + getDiskInfo() + "<br>";
    info += "🖥️  <b>OS:</b> " + getOSInfo() + "<br>";
    info += "🏷️  <b>Windows Type:</b> " + getWindowsType() + "<br>";
    info += "⭐  <b>Overall Rating:</b> " + getSystemRating() + "<br>";

    ui->textBrowser_info->setHtml(info);
*/

    ui->label_cpu_info->setText(getCPUName());
    ui->label_gpu_info->setText(getGPUInfoLabeled().replace("\n", "<br>"));
    ui->label_ram_info->setText(getRAMInfo());
    ui->label_disk_info->setText(getDiskInfo());
    ui->label_os_info->setText(getOSInfo());

    ui->label_rating_info->setText(getSystemRating());
}

mainmenu::~mainmenu()
{
    delete ui;
}


QString getCPUName() {
    HKEY hKey;
    char cpuBrand[100] = { 0 };
    DWORD size = sizeof(cpuBrand);

    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE,
                      "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
                      0, KEY_READ, &hKey) == ERROR_SUCCESS) {

        if (RegQueryValueExA(hKey, "ProcessorNameString", NULL, NULL, (LPBYTE)cpuBrand, &size) == ERROR_SUCCESS) {
            RegCloseKey(hKey);
            return QString(cpuBrand);
        }

        RegCloseKey(hKey);
    }
    return "Unknown CPU";
}

QString getGPUInfoLabeled() {
    IDXGIFactory* pFactory = nullptr;
    HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)(&pFactory));

    if (FAILED(hr)) return "DXGI factory creation failed";

    QString dedicated, integrated;

    UINT i = 0;
    IDXGIAdapter* pAdapter = nullptr;
    while (pFactory->EnumAdapters(i, &pAdapter) != DXGI_ERROR_NOT_FOUND) {
        DXGI_ADAPTER_DESC desc;
        pAdapter->GetDesc(&desc);

        QString name = QString::fromWCharArray(desc.Description);
        qDebug() << "DXGI GPU: " << name;

        if (name.contains("NVIDIA", Qt::CaseInsensitive) || name.contains("Radeon", Qt::CaseInsensitive)) {
            if (dedicated.isEmpty()) dedicated = name;
        } else if (name.contains("Intel", Qt::CaseInsensitive) || name.contains("Vega", Qt::CaseInsensitive)) {
            if (integrated.isEmpty()) integrated = name;
        }

        pAdapter->Release();
        ++i;
    }

    pFactory->Release();

    if (!dedicated.isEmpty() && !integrated.isEmpty())
        return "Dedicated: " + dedicated + " | Integrated: " + integrated;
    else if (!dedicated.isEmpty())
        return "Dedicated: " + dedicated;
    else if (!integrated.isEmpty())
        return "Integrated: " + integrated;
    else
        return "Unknown GPU";
}


QString getRAMInfo() {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);

    DWORDLONG totalPhysMB = statex.ullTotalPhys / (1024 * 1024);
    return QString("%1 MB").arg(totalPhysMB);
}

QString getDiskInfo() {
    QStorageInfo storage = QStorageInfo::root();

    qint64 total = storage.bytesTotal() / (1024 * 1024 * 1024);
    qint64 free = storage.bytesAvailable() / (1024 * 1024 * 1024);

    return QString("Total: %1 GB, Free: %2 GB").arg(total).arg(free);
}

QString getOSInfo() {
    return QSysInfo::prettyProductName();
}


QString getSystemRating() {
    QString cpu = getCPUName();
    QString ram = getRAMInfo();

    int score = 0;

    if (cpu.contains("i9") || cpu.contains("Ryzen 9") || cpu.contains("Ultra 9")) score += 3;
    else if (cpu.contains("i7") || cpu.contains("Ryzen 7") || cpu.contains("Ultra 7")) score += 2;
    else if (cpu.contains("i5") || cpu.contains("Ryzen 5")) score += 1;
    else score += 1;

    int ramAmount = ram.split(" ").first().toInt();
    if (ramAmount >= 32000) score += 3;
    else if (ramAmount >= 16000) score += 2;
    else if (ramAmount >= 8000) score += 1;
    else score += 1;

    if (score >= 6) return "High";
    if (score >= 4) return "Medium";
    return "Low";
}

void mainmenu::on_textBrowser_copyAvailable(bool b)
{
    Q_UNUSED(b);
}

void mainmenu::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/alexhebri"));
}

