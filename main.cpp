#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

#include "Src\Interface\MainWindow\mainwindow.h"
#include "Src\Core\no_reboot.h"

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow)
{
    // Create window
    {
        // Register the window class.
        const wchar_t CLASS_NAME[] = L"NoReboot Window Class";

        WNDCLASS wc = {};

        wc.lpfnWndProc = WindowProc;
        wc.hInstance = hInstance;
        wc.lpszClassName = CLASS_NAME;

        RegisterClass(&wc);

        // Create a hidden window.
        // https://stackoverflow.com/questions/47767786/how-to-prevent-a-system-shutdown-without-having-a-window?noredirect=1&lq=1
        HWND hwnd = CreateWindowEx(
            0,           // Optional window styles.
            CLASS_NAME,  // Window class
            L"NoReboot", // Window text
            0,           // Window style

            // Size and position
            0, 0, 0, 0,

            NULL,      // Parent window
            NULL,      // Menu
            hInstance, // Instance handle
            NULL       // Additional application data
        );

        if (hwnd == NULL)
        {
            return 0;
        }

        // ShowWindow(hwnd, nCmdShow);
    }

    NoReboot::setRebootPriority();

    // Run the message loop.
    {
        MSG msg = {};
        while (GetMessage(&msg, NULL, 0, 0) > 0)
        {
            DispatchMessage(&msg);
        }
    }

    return 0;
}
