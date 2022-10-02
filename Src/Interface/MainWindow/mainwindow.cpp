#include <windows.h>

#include "mainwindow.h"
#include "..\..\Define\define.h"
#include "..\..\Core\no_reboot.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_QUERYENDSESSION:
        PostMessage(hwnd, UM_REQUEST_BLOCK_REBOOT, NULL, NULL);
        return FALSE;
    case UM_REQUEST_BLOCK_REBOOT:
        NoReboot::showNoRebootMessage(hwnd);
        // TODO: Cancel use shutdown /a
        // https://stackoverflow.com/questions/6753215/run-process-during-windows-shutdown
        break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
