@echo off

%1 mshta vbscript:CreateObject("Shell.Application").ShellExecute("cmd.exe","/c %~s0 ::","","runas",1)(window.close)&&exit

cd /d %~dp0
xcopy "%cd%\ucrtbased.dll" "C:\Windows\SysWOW64"
xcopy "%cd%\vcruntime140d.dll" "C:\Windows\System32"
xcopy "%cd%\ucrtbased.dll" "C:\Windows\System32"
xcopy "%cd%\vcruntime140d.dll" "C:\Windows\SysWOW64"


pause 