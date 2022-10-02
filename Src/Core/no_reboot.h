#ifndef LAR_NO_REBOOT
#define LAR_NO_REBOOT

#include <windows.h>

// Static class
class NoReboot
{
public:
    // Tell Windows send reboot message to NoReboot first
    static void setRebootPriority();
    // Text to show on shutdown interface
    static void showNoRebootMessage(HWND hwnd);

private:
    // Disallow creating an instance of this object
    NoReboot();
};

#endif
