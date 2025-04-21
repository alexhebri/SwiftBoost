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
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"NetworkThrottlingIndex\" /t REG_DWORD /d \"ffffffff\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"SystemResponsiveness\" /t REG_DWORD /d \"00000000\" /f");
    system("bcdedit /set disabledynamictick yes");
    system("bcdedit /set useplatformclock false");
    system("ipconfig /flushdns");
    system("ipconfig /registerdns");
    system("ipconfig /release");
    system("ipconfig /renew");
    system("netsh winsock reset");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Winsock\" /v \"UseDelayedAcceptance\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Winsock\" /v \"MaxSockAddrLength\" /t REG_DWORD /d \"16\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Winsock\" /v \"MinSockAddrLength\" /t REG_DWORD /d \"16\" /f");

}


void network::on_network_throttling_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"NetworkThrottlingIndex\" /t REG_DWORD /d \"ffffffff\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"SystemResponsiveness\" /t REG_DWORD /d \"00000000\" /f");

}



void network::on_network_dynamic_clicked()
{
    system("bcdedit /set disabledynamictick yes");
    system("bcdedit /set useplatformclock false");

}


void network::on_network_ping_clicked()
{
    system("ipconfig /flushdns");
    system("ipconfig /registerdns");
    system("ipconfig /release");
    system("ipconfig /renew");
    system("netsh winsock reset");

    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Winsock\" /v \"UseDelayedAcceptance\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Winsock\" /v \"MaxSockAddrLength\" /t REG_DWORD /d \"16\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Winsock\" /v \"MinSockAddrLength\" /t REG_DWORD /d \"16\" /f");


}


void network::on_bloatware_removal_clicked()
{
    system("PowerShell -Command \"Get-AppxPackage *3DBuilder* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *Getstarted* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *solit* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *windowscommunicationsapps* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *zune* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *Sway* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *CommsPhone* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *ConnectivityStore* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *Drawboard PDF* | Remove-AppxPackage\"");

    system("PowerShell -Command \"Get-AppxPackage *bing* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *YourPhone* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *Xbox* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *People* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *SkypeApp* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *OfficeHub* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *OneNote* | Remove-AppxPackage\"");

}




void network::on_debloat_back_clicked()
{
    system("sc config DiagTrack start= disabled");
    system("sc config dmwappushservice start= disabled");
    system("sc config WSearch start= disabled");
    system("sc config BITS start= disabled");
    system("sc config WpnUserService start= disabled");
    system("sc config XblAuthManager start= disabled");
    system("sc config XblGameSave start= disabled");
    system("sc config XboxNetApiSvc start= disabled");
    system("sc stop DiagTrack");
    system("sc stop dmwappushservice");
    system("sc stop WSearch");
    system("sc stop BITS");
    system("sc stop WpnUserService");
    system("sc stop XblAuthManager");
    system("sc stop XblGameSave");
    system("sc stop XboxNetApiSvc");

}


void network::on_debloat_data_clicked()
{
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\AutoLogger\\AutoLogger-Diagtrack-Listener\" /v \"Start\" /t REG_DWORD /d 0 /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\AutoLogger\\SQMLogger\" /v \"Start\" /t REG_DWORD /d 0 /f");

    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search\" /v AllowCortana /t REG_DWORD /d 0 /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search\" /v DisableWebSearch /t REG_DWORD /d 1 /f");
    system("reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Search\" /v BingSearchEnabled /t REG_DWORD /d 0 /f");

    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Device Metadata\" /v PreventDeviceMetadataFromNetwork /t REG_DWORD /d 1 /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\DataCollection\" /v \"AllowTelemetry\" /t REG_DWORD /d 0 /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\MRT\" /v DontOfferThroughWUAU /t REG_DWORD /d 1 /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\SQMClient\\Windows\" /v \"CEIPEnable\" /t REG_DWORD /d 0 /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat\" /v \"AITEnable\" /t REG_DWORD /d 0 /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat\" /v \"DisableUAR\" /t REG_DWORD /d 1 /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection\" /v \"AllowTelemetry\" /t REG_DWORD /d 0 /f");

}


void network::on_debloat_all_clicked()
{
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\AutoLogger\\AutoLogger-Diagtrack-Listener\" /v \"Start\" /t REG_DWORD /d 0 /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\AutoLogger\\SQMLogger\" /v \"Start\" /t REG_DWORD /d 0 /f");

    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search\" /v AllowCortana /t REG_DWORD /d 0 /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search\" /v DisableWebSearch /t REG_DWORD /d 1 /f");
    system("reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Search\" /v BingSearchEnabled /t REG_DWORD /d 0 /f");

    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Device Metadata\" /v PreventDeviceMetadataFromNetwork /t REG_DWORD /d 1 /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\DataCollection\" /v \"AllowTelemetry\" /t REG_DWORD /d 0 /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\MRT\" /v DontOfferThroughWUAU /t REG_DWORD /d 1 /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\SQMClient\\Windows\" /v \"CEIPEnable\" /t REG_DWORD /d 0 /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat\" /v \"AITEnable\" /t REG_DWORD /d 0 /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat\" /v \"DisableUAR\" /t REG_DWORD /d 1 /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection\" /v \"AllowTelemetry\" /t REG_DWORD /d 0 /f");

    system("sc config DiagTrack start= disabled");
    system("sc config dmwappushservice start= disabled");
    system("sc config WSearch start= disabled");
    system("sc config BITS start= disabled");
    system("sc config WpnUserService start= disabled");
    system("sc config XblAuthManager start= disabled");
    system("sc config XblGameSave start= disabled");
    system("sc config XboxNetApiSvc start= disabled");
    system("sc stop DiagTrack");
    system("sc stop dmwappushservice");
    system("sc stop WSearch");
    system("sc stop BITS");
    system("sc stop WpnUserService");
    system("sc stop XblAuthManager");
    system("sc stop XblGameSave");
    system("sc stop XboxNetApiSvc");

    system("PowerShell -Command \"Get-AppxPackage *3DBuilder* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *Getstarted* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *solit* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *windowscommunicationsapps* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *zune* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *Sway* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *CommsPhone* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *ConnectivityStore* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *Drawboard PDF* | Remove-AppxPackage\"");

    system("PowerShell -Command \"Get-AppxPackage *bing* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *YourPhone* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *Xbox* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *People* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *SkypeApp* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *OfficeHub* | Remove-AppxPackage\"");
    system("PowerShell -Command \"Get-AppxPackage *OneNote* | Remove-AppxPackage\"");
}


void network::on_clean_all_clicked()
{
    system("del /q /s /f %temp%\\*");
    system("del /q /s /f %windir%\\Logs\\*");
    system("net stop wuauserv");
    system("rmdir /s /q %windir%\\SoftwareDistribution");
    system("net start wuauserv");
}


void network::on_clean_log_temp_clicked()
{
    system("del /q /s /f %temp%\\*");
    system("del /q /s /f %windir%\\Logs\\*");

}


void network::on_clean_cache_clicked()
{
    system("net stop wuauserv");
    system("rmdir /s /q %windir%\\SoftwareDistribution");
    system("net start wuauserv");
}

