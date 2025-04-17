#include "windowstweaks.h"
#include "ui_windowstweaks.h"

#include <iostream>
#include <windows.h>
#include <string>
#include <QInputDialog>
#include <QMessageBox>

using namespace std;

#define BEGIN_SYSTEM_CHANGE 100
#define APPLICATION_INSTALL 0

windowstweaks::windowstweaks(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::windowstweaks)
{
    ui->setupUi(this);

}

windowstweaks::~windowstweaks()
{
    delete ui;
}

typedef struct _RESTOREPOINTINFOW {
    DWORD dwEventType;
    DWORD dwRestorePtType;
    INT64 llSequenceNumber;
    WCHAR szDescription[256];
} RESTOREPOINTINFOW, *PRESTOREPOINTINFOW;

typedef struct _STATEMGRSTATUS {
    DWORD nStatus;
    INT64 llSequenceNumber;
} STATEMGRSTATUS, *PSTATEMGRSTATUS;

typedef BOOL(WINAPI* SRSetRestorePointWPtr)(PRESTOREPOINTINFOW, PSTATEMGRSTATUS);

int createRestorePoint(const wstring& description) {
    HMODULE hModule = LoadLibraryW(L"srclient.dll");
    if (!hModule) {
        wcerr << L"Failed to load srclient.dll" << endl;
        return -1;
    }

    auto SRSetRestorePointW = (SRSetRestorePointWPtr)GetProcAddress(hModule, "SRSetRestorePointW");
    if (!SRSetRestorePointW) {
        wcerr << L"Failed to locate SRSetRestorePointW function" << endl;
        FreeLibrary(hModule);
        return -1;
    }

    RESTOREPOINTINFOW rpInfo = {};
    STATEMGRSTATUS status = {};
    rpInfo.dwEventType = BEGIN_SYSTEM_CHANGE;
    rpInfo.dwRestorePtType = APPLICATION_INSTALL;

    wcsncpy(rpInfo.szDescription, description.c_str(), min(description.size(), size_t(255)));
    rpInfo.szDescription[255] = L'\0';

    if (!SRSetRestorePointW(&rpInfo, &status)) {
        wcerr << L"Failed to create restore point. Error code: " << status.nStatus << endl;
        FreeLibrary(hModule);
        return -1;
    }

    wcerr << L"Restore point created successfully." << endl;
    FreeLibrary(hModule);
    return 0;
}

void windowstweaks::on_restore_point_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Create Restore Point"),
                                         tr("Enter a description for the restore point:"),
                                         QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        std::wstring description = text.toStdWString();

        int result = createRestorePoint(description);
        if (result == 0) {
            QMessageBox::information(this, tr("Success"),
                                     tr("Restore point created successfully."));
        } else {
            QMessageBox::critical(this, tr("Error"),
                                  tr("Failed to create restore point. Error code: %1").arg(result));
        }
    }
}


void windowstweaks::on_disable_uac_clicked()
{
    int result = system("cmd /c REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v EnableLUA /t REG_DWORD /d 0 /f");


    if (result == 0) {
        QMessageBox::information(this, tr("Operation Complete"),
                                 tr("Command to disable User Account Control was executed.\n"));
    } else {
        QMessageBox::warning(this, tr("Operation Failed"),
                             tr("Failed to modify UAC settings. This requires administrator privileges."));
    }
}


void windowstweaks::on_windows_update_clicked()
{
    system("net stop wuauserv");
    system("net stop UsoSvc");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\" /v \"DoNotConnectToWindowsUpdateInternetLocations\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\" /v \"SetDisableUXWUAccess\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\\AU\" /v \"NoAutoUpdate\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\" /v \"ExcludeWUDriversInQualityUpdate\" /t REG_DWORD /d \"1\" /f");
}


void windowstweaks::on_disable_findmydevice_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Device Metadata\" /v \"PreventDeviceMetadataFromNetwork\" /t REG_DWORD /d \"1\" /f");
}


void windowstweaks::on_disable_transparency_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize\" /v \"EnableTransparency\" /t REG_DWORD /d \"0\" /f");

}


void windowstweaks::on_disable_loc_not_hgr_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\location\" /v \"Value\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\appDiagnostics\" /v \"Value\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\notifications\" /v \"Value\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced\" /v \"Start_TrackDocs\" /t REG_DWORD /d 0 /f");
    system("reg add \"HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced\" /v \"HideFileExt\" /t REG_DWORD /d 0 /f");
    system("net stop homegroupprovider");
    system("sc config homegroupprovider start= disabled");
    system("reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced\" /v HomeGroupDisabled /t REG_DWORD /d 1 /f");
    system("reg add \"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\" /v NoHomeGroup /t REG_DWORD /d 1 /f");
}




void windowstweaks::on_disable_game_cort_sync_clicked()
{
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR\" /v \"AppCaptureEnabled\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR\" /v \"GameDVR_Enabled\" /t REG_DWORD /d \"0\" /f");

    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search\" /v \"AllowCortana\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\SettingSync\\Groups\\Account\" /v \"Enabled\" /t REG_DWORD /d \"0\" /f");

    system("sc stop XboxLiveAuthManager");
    system("sc stop XboxNetApiSvc");
    system("sc config XboxLiveAuthManager start= disabled");
    system("sc config XboxNetApiSvc start= disabled");
}


void windowstweaks::on_enable_game_hardacc_clicked()
{
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\GameBar\" /v \"AllowAutoGameMode\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\GameBar\" /v \"AutoGameModeEnabled\" /t REG_DWORD /d \"1\" /f");

    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v \"HwSchMode\" /t REG_DWORD /d \"1\" /f");

}


void windowstweaks::on_disable_keys_narr_magn_clicked()
{
    system("reg add \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\StickyKeys\" /v \"Flags\" /t REG_SZ /d \"506\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\Keyboard Response\" /v \"Flags\" /t REG_SZ /d \"122\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\ToggleKeys\" /v \"Flags\" /t REG_SZ /d \"58\" /f");

    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Narrator\\NoRoam\" /v \"WinEnterLaunchEnabled\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\ScreenMagnifier\" /v \"Magnification\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Speech\" /v \"AllowOnlineSpeechRecognition\" /t REG_DWORD /d \"0\" /f");
}


void windowstweaks::on_disable_telemetry_and_data_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\System\" /v \"PublishUserActivities\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\System\" /v \"UploadUserActivities\" /t REG_DWORD /d \"0\" /f");

    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection\" /v \"AllowTelemetry\" /t REG_DWORD /d \"0\" /f");

}


void windowstweaks::on_disable_onedrive_unnapps_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppPrivacy\" /v \"LetAppsRunInBackground\" /t REG_DWORD /d \"2\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\OneDrive\" /v \"DisableFileSyncNGSC\" /t REG_DWORD /d \"1\" /f");
}


void windowstweaks::on_priority_and_mouse_keyboard_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet001\\Control\\PriorityControl\" /v \"Win32PrioritySeparation\" /t REG_SZ /d \"2a\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\kbdclass\\Parameters\" /v \"KeyboardDataQueueSize\" /t REG_DWORD /d \"23\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\mouclass\\Parameters\" /v \"MouseDataQueueSize\" /t REG_DWORD /d \"23\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\MouseKeys\" /v \"Flags\" /t REG_SZ /d \"42\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\Keyboard Response\" /v \"AutoRepeatDelay\" /t REG_SZ /d \"200\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Control Panel\\Mouse\" /v \"MouseHoverTime\" /t REG_SZ /d \"0\" /f");
}


void windowstweaks::on_run_all_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\location\" /v \"Value\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\appDiagnostics\" /v \"Value\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\notifications\" /v \"Value\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize\" /v \"EnableTransparency\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\\AU\" /v \"NoAutoUpdate\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR\" /v \"AppCaptureEnabled\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR\" /v \"GameDVR_Enabled\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search\" /v \"AllowCortana\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\SettingSync\\Groups\\Account\" /v \"Enabled\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\GameBar\" /v \"AllowAutoGameMode\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\GameBar\" /v \"AutoGameModeEnabled\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v \"HwSchMode\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\StickyKeys\" /v \"Flags\" /t REG_SZ /d \"506\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\Keyboard Response\" /v \"Flags\" /t REG_SZ /d \"122\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\ToggleKeys\" /v \"Flags\" /t REG_SZ /d \"58\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\MouseKeys\" /v \"Flags\" /t REG_SZ /d \"42\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\Narrator\\NoRoam\" /v \"WinEnterLaunchEnabled\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\ScreenMagnifier\" /v \"Magnification\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Speech\" /v \"AllowOnlineSpeechRecognition\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\System\" /v \"PublishUserActivities\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\System\" /v \"UploadUserActivities\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection\" /v \"AllowTelemetry\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppPrivacy\" /v \"LetAppsRunInBackground\" /t REG_DWORD /d \"2\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\OneDrive\" /v \"DisableFileSyncNGSC\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet001\\Control\\PriorityControl\" /v \"Win32PrioritySeparation\" /t REG_SZ /d \"2a\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Control Panel\\Accessibility\\Keyboard Response\" /v \"AutoRepeatDelay\" /t REG_SZ /d \"200\" /f");
    system("reg add \"HKEY_CURRENT_USER\\Control Panel\\Mouse\" /v \"MouseHoverTime\" /t REG_SZ /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\kbdclass\\Parameters\" /v \"KeyboardDataQueueSize\" /t REG_DWORD /d \"23\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\mouclass\\Parameters\" /v \"MouseDataQueueSize\" /t REG_DWORD /d \"23\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Device Metadata\" /v \"PreventDeviceMetadataFromNetwork\" /t REG_DWORD /d \"1\" /f");

    system("sc stop XboxLiveAuthManager");
    system("sc stop XboxNetApiSvc");
    system("sc config XboxLiveAuthManager start= disabled");
    system("sc config XboxNetApiSvc start= disabled");

    system("net stop wuauserv");
    system("net stop UsoSvc");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\" /v \"DoNotConnectToWindowsUpdateInternetLocations\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\" /v \"SetDisableUXWUAccess\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\\AU\" /v \"NoAutoUpdate\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\" /v \"ExcludeWUDriversInQualityUpdate\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced\" /v \"Start_TrackDocs\" /t REG_DWORD /d 0 /f");
    system("net stop homegroupprovider");
    system("sc config homegroupprovider start= disabled");
    system("reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced\" /v HomeGroupDisabled /t REG_DWORD /d 1 /f");
    system("reg add \"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\" /v NoHomeGroup /t REG_DWORD /d 1 /f");
    system("reg add \"HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced\" /v \"HideFileExt\" /t REG_DWORD /d 0 /f");

}

