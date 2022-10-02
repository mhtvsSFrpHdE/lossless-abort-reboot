# lossless-abort-reboot

Cancel, abort, and block unwanted reboots, without losing the running process.

## How to use

### Start

Download the `LosslessAbortReboot.exe` and run it at startup.  
Do not use x86 exe on x64 system, it's not work.  
You can type `shell:startup` in the explorer address bar,  
and create a shortcut in this folder to run exe on startup.

The program has no interface but simply runs in the background,  
so you won't see any feedback after a double click.  
This is normal, so be careful, or you can easily open multiple instances.

To confirm the program is running, go to the task manager.

### Exit

After the program start, it will tell the operating system:  
I will be the first one to handle the shutdown message.  
However, when the program receives a shutdown message,  
it will do nothing but keeps delaying the shutdown.  
So other processes are "protected" from being killed.

Windows 10 will wait 1 minute, then back to the lock screen but cancel the shutdown.  
To truly shutdown, you need to kill the process.  
You can run `taskkill /f /im LosslessAbortReboot.exe`, or use task manager.  
After that, shutdown is allowed.

## Side effect

Even the `LosslessAbortReboot.exe` can block a shutdown,  
but if the user did not respond to the shutdown interface (click on cancel),  
all other PC programs will hang for about 1 minute until timeout.  
This is bad for server-side applications,  
you will need other methods to enhance the effect.  
See Background for more information.

## Background

Until Windows 10 become a thing,  
people lacked the imagination of "a PC can constantly reboot itself".  
So most of the programs have no interaction with certain Windows APIs.

The result is whether the user or program submits a shutdown request,  
many programs are just being killed and losing status and data.  
Some programs have the interaction, but others don't.

After Microsoft decided to push updates more aggressively,  
things go bad. Let's assume a scenario:

Microsoft just released a new update, download and install in the background.  
A user just finished the day of work,  
he has 10 hours of media encoding project in total, already running 7 hours.  
By plan, the PC will continue to work for the rest of 3 hours,  
and the user will leave the office room and back home.

Soon, after the download is completed, Microsoft shows a dialog that says  
"PC will reboot in 60 seconds to install update".  
But nobody is looking at the PC. So the PC is sure to go reboot soon.

In this case, a `notepad.exe` will show a dialog to ask the user to save unsaved text,  
but `ffmpeg.exe` are gone and lost the past 7 hours of work progress.  
When the user gets back tomorrow, there's nothing left on the desktop.  
He ends up having to deal with the project deadline with another 10 hours of encoding.

The program must actively call the Windows API, so they have a chance to save data.  
Without the call, the program is simply being killed.
The truth is, even if you've decided to call the API,  
it's hard to determine a program that can  
"pause at any time, then resume after reboot" without losing efficiency.  
The task is basically impossible.  
It may possible, but why don't you write your own software to do things?  
The reason you don't do it is the reason why developers can't.

I designed two solutions to fix such a problem.

One is the "LosslessAbortReboot.exe",  
this one can save you from a mess.

Another is the "good-old-windows-update",  
the one that prevents Windows download updates without a permit.

The best is to use "good-old-windows-update",  
and run "LosslessAbortReboot.exe" as a guard  
in case the first solution failed against Microsoft.
