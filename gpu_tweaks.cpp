#include "gpu_tweaks.h"
#include "ui_gpu_tweaks.h"

gpu_tweaks::gpu_tweaks(QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::gpu_tweaks)
{
    ui->setupUi(this);
}

gpu_tweaks::~gpu_tweaks()
{
    delete ui;
}

void gpu_tweaks::on_aaa_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v \"TdrDelay\" /t REG_DWORD /d \"10\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v \"TdrDdiDelay\" /t REG_DWORD /d \"10\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v \"TdrLevel\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v \"TdrLimitCount\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerSettings\\54533251-82be-4824-96c1-47b60b740d00\\943c8cb6-6f93-4227-ad87-e9a3feec08d1\" /v \"Attributes\" /t REG_SZ /d \"2\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Services\\nvlddmkm\\FTS\" /v \"EnableRID61684\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Affinity\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Background Only\" /t REG_SZ /d \"False\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Clock Rate\" /t REG_DWORD /d \"10000\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"GPU Priority\" /t REG_DWORD /d \"8\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Priority\" /t REG_DWORD /d \"6\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Scheduling Category\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"SFIO Priority\" /t REG_SZ /d \"High\" /f");

    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"ExitLatency\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"ExitLatencyCheckEnabled\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"Latency\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"LatencyToleranceDefault\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"LatencyToleranceFSVP\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"LatencyTolerancePerfOverride\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"LatencyToleranceScreenOffIR\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"LatencyToleranceVSyncEnabled\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"RtlCapabilityCheckLatency\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"QosManagesIdleProcessors\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DisableVsyncLatencyUpdate\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DisableSensorWatchdog\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"CoalescingTimerInterval\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"InterruptSteeringDisabled\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"LowLatencyScalingPercentage\" /t REG_DWORD /d \"100\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"HighPerformance\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"HighestPerformance\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"MinimumThrottlePercent\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"MaximumThrottlePercent\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"MaximumPerformancePercent\" /t REG_DWORD /d \"100\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"InitialUnparkCount\" /t REG_DWORD /d \"100\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultD3TransitionLatencyActivelyUsed\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultD3TransitionLatencyIdleLongTime\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultD3TransitionLatencyIdleMonitorOff\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultD3TransitionLatencyIdleNoContext\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultD3TransitionLatencyIdleShortTime\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultD3TransitionLatencyIdleVeryLongTime\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceIdle0\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceIdle0MonitorOff\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceIdle1\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceIdle1MonitorOff\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceMemory\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceNoContext\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceNoContextMonitorOff\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceOther\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceTimerPeriod\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultMemoryRefreshLatencyToleranceActivelyUsed\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultMemoryRefreshLatencyToleranceMonitorOff\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultMemoryRefreshLatencyToleranceNoContext\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"Latency\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"MaxIAverageGraphicsLatencyInOneBucket\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"MiracastPerfTrackGraphicsLatency\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"MonitorLatencyTolerance\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"MonitorRefreshLatencyTolerance\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"TransitionLatency\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"EnablePreemption\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v \"HwSchMode\" /t REG_DWORD /d \"2\" /f");

}


void gpu_tweaks::on_nvidia_reg_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v \"TdrDelay\" /t REG_DWORD /d \"10\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v \"TdrDdiDelay\" /t REG_DWORD /d \"10\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v \"TdrLevel\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v \"TdrLimitCount\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerSettings\\54533251-82be-4824-96c1-47b60b740d00\\943c8cb6-6f93-4227-ad87-e9a3feec08d1\" /v \"Attributes\" /t REG_SZ /d \"2\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Services\\nvlddmkm\\FTS\" /v \"EnableRID61684\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Affinity\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Background Only\" /t REG_SZ /d \"False\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Clock Rate\" /t REG_DWORD /d \"10000\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"GPU Priority\" /t REG_DWORD /d \"8\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Priority\" /t REG_DWORD /d \"6\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Scheduling Category\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"SFIO Priority\" /t REG_SZ /d \"High\" /f");
}


void gpu_tweaks::on_nvidia_advanced_clicked()
{
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"ExitLatency\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"ExitLatencyCheckEnabled\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"Latency\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"LatencyToleranceDefault\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"LatencyToleranceFSVP\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"LatencyTolerancePerfOverride\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"LatencyToleranceScreenOffIR\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"LatencyToleranceVSyncEnabled\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"RtlCapabilityCheckLatency\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"QosManagesIdleProcessors\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DisableVsyncLatencyUpdate\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DisableSensorWatchdog\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"CoalescingTimerInterval\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"InterruptSteeringDisabled\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"LowLatencyScalingPercentage\" /t REG_DWORD /d \"100\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"HighPerformance\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"HighestPerformance\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"MinimumThrottlePercent\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"MaximumThrottlePercent\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"MaximumPerformancePercent\" /t REG_DWORD /d \"100\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"InitialUnparkCount\" /t REG_DWORD /d \"100\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultD3TransitionLatencyActivelyUsed\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultD3TransitionLatencyIdleLongTime\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultD3TransitionLatencyIdleMonitorOff\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultD3TransitionLatencyIdleNoContext\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultD3TransitionLatencyIdleShortTime\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultD3TransitionLatencyIdleVeryLongTime\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceIdle0\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceIdle0MonitorOff\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceIdle1\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceIdle1MonitorOff\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceMemory\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceNoContext\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceNoContextMonitorOff\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceOther\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultLatencyToleranceTimerPeriod\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultMemoryRefreshLatencyToleranceActivelyUsed\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultMemoryRefreshLatencyToleranceMonitorOff\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"DefaultMemoryRefreshLatencyToleranceNoContext\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"Latency\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"MaxIAverageGraphicsLatencyInOneBucket\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"MiracastPerfTrackGraphicsLatency\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"MonitorLatencyTolerance\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"MonitorRefreshLatencyTolerance\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"TransitionLatency\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\" /v \"EnablePreemption\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v \"HwSchMode\" /t REG_DWORD /d \"2\" /f");

}


void gpu_tweaks::on_amd_all_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableDMACopy\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableBlockWrite\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"StutterMode\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"EnableUlps\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"EnableUlps_NA\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"PP_SclkDeepSleepDisable\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"PP_ThermalAutoThrottlingEnable\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableDrmdmaPowerGating\" /t REG_DWORD /d \"1\" /f");

    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\amdkmdap\\Parameters\" /v \"ThreadPriority\" /t REG_DWORD /d 0x1F /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"Main3D_DEF\" /t REG_SZ /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"Main3D\" /t REG_BINARY /d \"31,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"FlipQueueSize\" /t REG_BINARY /d \"31,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"ShaderCache\" /t REG_BINARY /d \"32,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"Tessellation_OPTION\" /t REG_BINARY /d \"32,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"Tessellation\" /t REG_BINARY /d \"31,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"VSyncControl\" /t REG_BINARY /d \"30,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"TFQ\" /t REG_BINARY /d \"32,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\DAL2_DATA__2_0\\DisplayPath_4\\EDID_D109_78E9\\Option\" /v \"ProtectionControl\" /t REG_BINARY /d \"01,00,00,00,01,00,00,00\" /f");

    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"EnableVceSwClockGating\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"EnableUvdClockGating\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableVCEPowerGating\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableUVDPowerGatingDynamic\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisablePowerGating\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableSAMUPowerGating\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableFBCForFullScreenApp\" /t REG_SZ /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableFBCSupport\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableEarlySamuInit\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"PP_GPUPowerDownEnabled\" /t REG_DWORD /d \"0\" /f");

    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"MLF\" /t REG_BINARY /d \"30,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"EQAA\" /t REG_BINARY /d \"30,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"PowerState\" /t REG_BINARY /d \"30,00\" /f");

    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\amdkmdag\\UMD\" /v \"FlipQueueSize\" /t REG_SZ /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\amdkmdag\\UMD\" /v \"Main3D\" /t REG_BINARY /d \"31,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\amdkmdag\\UMD\" /v \"Main3D_DEF\" /t REG_SZ /d \"1\" /f");

    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"Tessellation_OPTION\" /t REG_BINARY /d \"32,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"Tessellation\" /t REG_BINARY /d \"31,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"TFQ\" /t REG_BINARY /d \"32,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"EnableUlps\" /t REG_DWORD /d \"0\" /f");


}


void gpu_tweaks::on_amd_reg_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableDMACopy\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableBlockWrite\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"StutterMode\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"EnableUlps\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"EnableUlps_NA\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"PP_SclkDeepSleepDisable\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"PP_ThermalAutoThrottlingEnable\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableDrmdmaPowerGating\" /t REG_DWORD /d \"1\" /f");

    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\amdkmdap\\Parameters\" /v \"ThreadPriority\" /t REG_DWORD /d 0x1F /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"Main3D_DEF\" /t REG_SZ /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"Main3D\" /t REG_BINARY /d \"31,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"FlipQueueSize\" /t REG_BINARY /d \"31,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"ShaderCache\" /t REG_BINARY /d \"32,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"Tessellation_OPTION\" /t REG_BINARY /d \"32,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"Tessellation\" /t REG_BINARY /d \"31,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"VSyncControl\" /t REG_BINARY /d \"30,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"TFQ\" /t REG_BINARY /d \"32,00\" /f");
    //system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\amdkmdap\\Parameters\" /v \"ThreadPriority\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\DAL2_DATA__2_0\\DisplayPath_4\\EDID_D109_78E9\\Option\" /v \"ProtectionControl\" /t REG_BINARY /d \"01,00,00,00,01,00,00,00\" /f");

}


void gpu_tweaks::on_amd_boost_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"EnableVceSwClockGating\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"EnableUvdClockGating\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableVCEPowerGating\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableUVDPowerGatingDynamic\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisablePowerGating\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableSAMUPowerGating\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableFBCForFullScreenApp\" /t REG_SZ /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableFBCSupport\" /t REG_DWORD /d \"0\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"DisableEarlySamuInit\" /t REG_DWORD /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"PP_GPUPowerDownEnabled\" /t REG_DWORD /d \"0\" /f");

    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"MLF\" /t REG_BINARY /d \"30,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"EQAA\" /t REG_BINARY /d \"30,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"PowerState\" /t REG_BINARY /d \"30,00\" /f");

    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\amdkmdag\\UMD\" /v \"FlipQueueSize\" /t REG_SZ /d \"1\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\amdkmdag\\UMD\" /v \"Main3D\" /t REG_BINARY /d \"31,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\amdkmdag\\UMD\" /v \"Main3D_DEF\" /t REG_SZ /d \"1\" /f");

}


void gpu_tweaks::on_amd_radeon_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"Tessellation_OPTION\" /t REG_BINARY /d \"32,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"Tessellation\" /t REG_BINARY /d \"31,00\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\\UMD\" /v \"TFQ\" /t REG_BINARY /d \"32,00\" /f");

}


void gpu_tweaks::on_amd_ultralow_clicked()
{
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000\" /v \"EnableUlps\" /t REG_DWORD /d \"0\" /f");

}

