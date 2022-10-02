cd /d %~dp0

call env.bat

@set path=%path%;%ninjaPath%

call clean_vscode.bat
@REM VSCode chromium gpu
start "" "%vsCodePath%" "%vsCodeWorkspace%" --enable-gpu-rasterization