#include "power_tweaks.h"
#include "ui_power_tweaks.h"

power_tweaks::power_tweaks(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::power_tweaks)
{
    ui->setupUi(this);
}

power_tweaks::~power_tweaks()
{
    delete ui;
}

void power_tweaks::on_plan_ultimate_clicked()
{
    system("powercfg -duplicatescheme e9a42b02-d5df-448d-aa00-03f14749eb61");
    system("powercfg -setactive e9a42b02-d5df-448d-aa00-03f14749eb61");
}




void power_tweaks::on_plan_high_clicked()
{
    system("powercfg -duplicatescheme 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c");
    system("powercfg -setactive 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c");
}


void power_tweaks::on_extra_performance_clicked()
{
    system("powercfg -duplicatescheme e9a42b02-d5df-448d-aa00-03f14749eb61");
    system("powercfg -setactive e9a42b02-d5df-448d-aa00-03f14749eb61");

    system("powercfg -setacvalueindex scheme_current sub_processor PROCTHROTTLEMAX 100");
    system("powercfg -setdcvalueindex scheme_current sub_processor PROCTHROTTLEMAX 100");

    system("powercfg -setacvalueindex scheme_current sub_disk DISKIDLE 0");
    system("powercfg -setdcvalueindex scheme_current sub_disk DISKIDLE 0");

    system("powercfg -setacvalueindex scheme_current sub_processor PROCTHROTTLEMIN 100");
    system("powercfg -setdcvalueindex scheme_current sub_processor PROCTHROTTLEMIN 100");

    system("powercfg -setacvalueindex scheme_current sub_usb USBSELECTSUSPEND 0");
    system("powercfg -setdcvalueindex scheme_current sub_usb USBSELECTSUSPEND 0");

    system("powercfg -setacvalueindex scheme_current sub_pciexpress ASPM 0");
    system("powercfg -setdcvalueindex scheme_current sub_pciexpress ASPM 0");

    system("powercfg -setacvalueindex scheme_current sub_sleep STANDBYIDLE 0");
    system("powercfg -setdcvalueindex scheme_current sub_sleep STANDBYIDLE 0");

    system("powercfg -setacvalueindex scheme_current sub_video VIDEOIDLE 0");
    system("powercfg -setdcvalueindex scheme_current sub_video VIDEOIDLE 0");


    system("powercfg -apply scheme_current");
}


void power_tweaks::on_disable_cpupark_clicked()
{
    system("powercfg -setacvalueindex scheme_current sub_processor PROCTHROTTLEMIN 100");
    system("powercfg -setdcvalueindex scheme_current sub_processor PROCTHROTTLEMIN 100");

    system("powercfg -setacvalueindex scheme_current sub_processor CPMINCORES 100");
    system("powercfg -setdcvalueindex scheme_current sub_processor CPMINCORES 100");

}


void power_tweaks::on_gpu_Max_clicked()
{
    system("powercfg -setacvalueindex scheme_current sub_graphics GPUPOWERMODE 1");
    system("powercfg -setdcvalueindex scheme_current sub_graphics GPUPOWERMODE 1");

}


void power_tweaks::on_mmcss_clicked()
{
    system("powercfg -setacvalueindex scheme_current sub_disk DISKIDLE 0");
    system("powercfg -setdcvalueindex scheme_current sub_disk DISKIDLE 0");

    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"SystemResponsiveness\" /t REG_DWORD /d \"00000000\" /f");

}


void power_tweaks::on_disable_powerthrottling_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerThrottling\" /v \"PowerThrottling\" /t REG_DWORD /d \"0\" /f");
    system("powercfg -setactive 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c");

}


void power_tweaks::on_disable_sleep_clicked()
{
    system("powercfg -change -standby-timeout-ac 0");
    system("powercfg -h off");
}


void power_tweaks::on_disable_fullscreenglobally_clicked()
{
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Layers\" /v \"C:\\Program Files\\*\\*.exe\" /t REG_SZ /d \"~ HIGHDPIAWARE\" /f");

}


void power_tweaks::on_disable_automaint_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Schedule\\TaskCache\\Tasks\\{5038FC98-3B7E-4F9A-8AAB-0B0B3B4F0A3D}\" /v \"Enabled\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Power\" /v \"HiberbootEnabled\" /t REG_DWORD /d \"0\" /f");

}


void power_tweaks::on_run_ultimate_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Schedule\\TaskCache\\Tasks\\{5038FC98-3B7E-4F9A-8AAB-0B0B3B4F0A3D}\" /v \"Enabled\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Power\" /v \"HiberbootEnabled\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Layers\" /v \"C:\\Program Files\\*\\*.exe\" /t REG_SZ /d \"~ HIGHDPIAWARE\" /f");
    system("powercfg -change -standby-timeout-ac 0");
    system("powercfg -h off");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerThrottling\" /v \"PowerThrottling\" /t REG_DWORD /d \"0\" /f");
    system("powercfg -setactive 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c");
    system("powercfg -setacvalueindex scheme_current sub_disk DISKIDLE 0");
    system("powercfg -setdcvalueindex scheme_current sub_disk DISKIDLE 0");

    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"SystemResponsiveness\" /t REG_DWORD /d \"00000000\" /f");
    system("powercfg -setacvalueindex scheme_current sub_graphics GPUPOWERMODE 1");
    system("powercfg -setdcvalueindex scheme_current sub_graphics GPUPOWERMODE 1");
    system("powercfg -setacvalueindex scheme_current sub_usb USBSELECTSUSPEND 0");
    system("powercfg -setdcvalueindex scheme_current sub_usb USBSELECTSUSPEND 0");



    system("powercfg -setacvalueindex scheme_current sub_processor CPMINCORES 100");
    system("powercfg -setdcvalueindex scheme_current sub_processor CPMINCORES 100");
    system("powercfg -setacvalueindex scheme_current sub_processor PROCTHROTTLEMIN 100");
    system("powercfg -setdcvalueindex scheme_current sub_processor PROCTHROTTLEMIN 100");

    system("powercfg -duplicatescheme e9a42b02-d5df-448d-aa00-03f14749eb61");
    system("powercfg -setactive e9a42b02-d5df-448d-aa00-03f14749eb61");

    system("powercfg -duplicatescheme e9a42b02-d5df-448d-aa00-03f14749eb61");
    system("powercfg -setactive e9a42b02-d5df-448d-aa00-03f14749eb61");

    system("powercfg -setacvalueindex scheme_current sub_processor PROCTHROTTLEMAX 100");
    system("powercfg -setdcvalueindex scheme_current sub_processor PROCTHROTTLEMAX 100");

    system("powercfg -setacvalueindex scheme_current sub_usb USBSELECTSUSPEND 0");
    system("powercfg -setdcvalueindex scheme_current sub_usb USBSELECTSUSPEND 0");

    system("powercfg -setacvalueindex scheme_current sub_pciexpress ASPM 0");
    system("powercfg -setdcvalueindex scheme_current sub_pciexpress ASPM 0");

    system("powercfg -setacvalueindex scheme_current sub_sleep STANDBYIDLE 0");
    system("powercfg -setdcvalueindex scheme_current sub_sleep STANDBYIDLE 0");

    system("powercfg -setacvalueindex scheme_current sub_video VIDEOIDLE 0");
    system("powercfg -setdcvalueindex scheme_current sub_video VIDEOIDLE 0");


    system("powercfg -apply scheme_current");

}


void power_tweaks::on_run_high_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Schedule\\TaskCache\\Tasks\\{5038FC98-3B7E-4F9A-8AAB-0B0B3B4F0A3D}\" /v \"Enabled\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Power\" /v \"HiberbootEnabled\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Layers\" /v \"C:\\Program Files\\*\\*.exe\" /t REG_SZ /d \"~ HIGHDPIAWARE\" /f");
    system("powercfg -change -standby-timeout-ac 0");
    system("powercfg -h off");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerThrottling\" /v \"PowerThrottling\" /t REG_DWORD /d \"0\" /f");
    system("powercfg -setactive 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c");
    system("powercfg -setacvalueindex scheme_current sub_disk DISKIDLE 0");
    system("powercfg -setdcvalueindex scheme_current sub_disk DISKIDLE 0");

    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"SystemResponsiveness\" /t REG_DWORD /d \"00000000\" /f");
    system("powercfg -setacvalueindex scheme_current sub_graphics GPUPOWERMODE 1");
    system("powercfg -setdcvalueindex scheme_current sub_graphics GPUPOWERMODE 1");


    system("powercfg -setacvalueindex scheme_current sub_processor CPMINCORES 100");
    system("powercfg -setdcvalueindex scheme_current sub_processor CPMINCORES 100");
    system("powercfg -setacvalueindex scheme_current sub_processor PROCTHROTTLEMIN 100");
    system("powercfg -setdcvalueindex scheme_current sub_processor PROCTHROTTLEMIN 100");
    system("powercfg -setacvalueindex scheme_current sub_usb USBSELECTSUSPEND 0");
    system("powercfg -setdcvalueindex scheme_current sub_usb USBSELECTSUSPEND 0");


    system("powercfg -duplicatescheme 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c");
    system("powercfg -setactive 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c");
}

