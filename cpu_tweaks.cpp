#include "cpu_tweaks.h"
#include "ui_cpu_tweaks.h"

cpu_tweaks::cpu_tweaks(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::cpu_tweaks)
{
    ui->setupUi(this);
}

cpu_tweaks::~cpu_tweaks()
{
    delete ui;
}

void cpu_tweaks::on_cpu_runall_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Affinity\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Background Only\" /t REG_SZ /d \"False\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Clock Rate\" /t REG_DWORD /d \"10000\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"GPU Priority\" /t REG_DWORD /d \"8\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Priority\" /t REG_DWORD /d \"2\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Scheduling Category\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"SFIO Priority\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"NetworkThrottlingIndex\" /t REG_DWORD /d \"4294967295\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"SystemResponsiveness\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"NetworkThrottlingIndex\" /t REG_DWORD /d \"4294967295\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"SystemResponsiveness\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Affinity\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Background Only\" /t REG_SZ /d \"False\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Clock Rate\" /t REG_DWORD /d \"10000\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Scheduling Category\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"SFIO Priority\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"GPU Priority\" /t REG_DWORD /d \"8\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Priority\" /t REG_DWORD /d \"6\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"GPU Priority\" /t REG_DWORD /d \"8\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Priority\" /t REG_DWORD /d \"6\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Scheduling Category\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"SFIO Priority\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR\" /v \"AppCaptureEnabled\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR\" /v \"GameDVR_Enabled\" /t REG_DWORD /d \"0\" /f");


}


void cpu_tweaks::on_cpu_general_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Affinity\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Background Only\" /t REG_SZ /d \"False\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Clock Rate\" /t REG_DWORD /d \"10000\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"GPU Priority\" /t REG_DWORD /d \"8\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Priority\" /t REG_DWORD /d \"2\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Scheduling Category\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"SFIO Priority\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR\" /v \"AppCaptureEnabled\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR\" /v \"GameDVR_Enabled\" /t REG_DWORD /d \"0\" /f");

}


void cpu_tweaks::on_cpu_responsiveness_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"NetworkThrottlingIndex\" /t REG_DWORD /d \"4294967295\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"SystemResponsiveness\" /t REG_DWORD /d \"0\" /f");
}


void cpu_tweaks::on_cpu_intel_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Affinity\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Background Only\" /t REG_SZ /d \"False\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Clock Rate\" /t REG_DWORD /d \"10000\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Scheduling Category\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"SFIO Priority\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"GPU Priority\" /t REG_DWORD /d \"8\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Priority\" /t REG_DWORD /d \"6\" /f");

}


void cpu_tweaks::on_cpu_amd_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"GPU Priority\" /t REG_DWORD /d \"8\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Priority\" /t REG_DWORD /d \"6\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Scheduling Category\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"SFIO Priority\" /t REG_SZ /d \"High\" /f");

}


void cpu_tweaks::on_disable_idle_clicked()
{
    system("powercfg /SETACVALUEINDEX SCHEME_CURRENT SUB_PROCESSOR IDLEDISABLE 1 && powercfg /SETACTIVE SCHEME_CURRENT");

}


void cpu_tweaks::on_enable_idle_clicked()
{
    system("powercfg /SETACVALUEINDEX SCHEME_CURRENT SUB_PROCESSOR IDLEDISABLE 0 && powercfg /SETACTIVE SCHEME_CURRENT");

}

