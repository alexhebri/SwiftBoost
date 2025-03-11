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

