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

void revert_and_services::on_disable_unwanted_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\FontCache\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\FontCache3.0.0.0\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\GraphicsPerfSvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\stisvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\WerSvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\PcaSvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\Wecsvc\" /v \"Start\" /t REG_DWORD /d 4 /f");

    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\FontCache\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\FontCache3.0.0.0\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\GraphicsPerfSvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\stisvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\WerSvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\PcaSvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\Wecsvc\" /v \"Start\" /t REG_DWORD /d 4 /f");

}


void revert_and_services::on_disable_unnecessary_clicked()
{
    //system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\WbioSrvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\FontCache\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\FontCache3.0.0.0\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\GraphicsPerfSvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\stisvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\WerSvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\PcaSvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\Wecsvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
}


void revert_and_services::on_disable_telemetry_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\DiagTrack\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\dmwappushservice\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\diagsvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\DPS\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\diagnosticshub.standardcollector.service\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\WdiServiceHost\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\WdiSystemHost\" /v \"Start\" /t REG_DWORD /d 4 /f");
}


void revert_and_services::on_disable_bluetooth_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\bthserv\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\BthAvctpSvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\BthHFSrv\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\BthEnum\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\bthmodem\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\bthenum\" /v \"Start\" /t REG_DWORD /d 4 /f");

}


void revert_and_services::on_disable_xbox_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\XblGameSave\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\XboxNetApiSvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\XboxGipSvc\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\XblAuthManager\" /v \"Start\" /t REG_DWORD /d 4 /f");

}


void revert_and_services::on_disable_printer_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\Spooler\" /v \"Start\" /t REG_DWORD /d 4 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\PrintNotify\" /v \"Start\" /t REG_DWORD /d 4 /f");
}



void revert_and_services::on_disable_updates_clicked()
{
    system("sc config wuauserv start= disabled");
    system("sc stop wuauserv");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\" /v \"DisableWindowsUpdateAccess\" /t REG_DWORD /d \"1\" /f");

}


void revert_and_services::on_disable_notifications_clicked()
{
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\PushNotifications\" /v \"ToastEnabled\" /t REG_DWORD /d \"0\" /f");
}


void revert_and_services::on_disable_transparency_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize\" /v \"EnableTransparency\" /t REG_DWORD /d \"0\" /f");
}


void revert_and_services::on_disable_findmydevice_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\DeviceCensus\" /v \"AllowDeviceCensus\" /t REG_DWORD /d \"0\" /f");
}


void revert_and_services::on_disable_power_throttling_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerThrottling\" /v \"PowerThrottlingOff\" /t REG_DWORD /d \"1\" /f");
}


void revert_and_services::on_enable_bluetooth_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\bthserv\" /v \"Start\" /t REG_DWORD /d 3 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\BthAvctpSvc\" /v \"Start\" /t REG_DWORD /d 3 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\BthHFSrv\" /v \"Start\" /t REG_DWORD /d 3 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\BthEnum\" /v \"Start\" /t REG_DWORD /d 3 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\bthmodem\" /v \"Start\" /t REG_DWORD /d 3 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\bthenum\" /v \"Start\" /t REG_DWORD /d 3 /f");

}


void revert_and_services::on_enable_xbox_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\XblGameSave\" /v \"Start\" /t REG_DWORD /d 3 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\XboxNetApiSvc\" /v \"Start\" /t REG_DWORD /d 3 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\XboxGipSvc\" /v \"Start\" /t REG_DWORD /d 3 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\XblAuthManager\" /v \"Start\" /t REG_DWORD /d 3 /f");


}


void revert_and_services::on_enable_printer_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\Spooler\" /v \"Start\" /t REG_DWORD /d 2 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\PrintNotify\" /v \"Start\" /t REG_DWORD /d 3 /f");

}


void revert_and_services::on_enable_updates_clicked()
{
    system("sc config wuauserv start= auto");
    system("sc start wuauserv");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\" /v \"DisableWindowsUpdateAccess\" /t REG_DWORD /d \"0\" /f");

}


void revert_and_services::on_enable_notifications_clicked()
{
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\PushNotifications\" /v \"ToastEnabled\" /t REG_DWORD /d \"1\" /f");

}


void revert_and_services::on_enable_transparency_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize\" /v \"EnableTransparency\" /t REG_DWORD /d \"1\" /f");

}


void revert_and_services::on_enable_findmydevice_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Device Metadata\" /v \"PreventDeviceMetadataFromNetwork\" /t REG_DWORD /d \"0\" /f");

}


void revert_and_services::on_enable_power_throttling_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerThrottling\" /v \"PowerThrottling\" /t REG_DWORD /d \"0\" /f");

}

