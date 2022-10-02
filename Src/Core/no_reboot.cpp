#include "no_reboot.h"

void NoReboot::setRebootPriority()
{
    // 4FF: Try to be the first one to receive shutdown message
    BOOL setResult = SetProcessShutdownParameters(0x4FF, SHUTDOWN_NORETRY);
}
void NoReboot::showNoRebootMessage(HWND hwnd)
{
    ShutdownBlockReasonCreate(hwnd, L"Captured may unwanted shutdown.");
}
