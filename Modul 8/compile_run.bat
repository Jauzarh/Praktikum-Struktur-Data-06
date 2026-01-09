@echo off
echo ======================================
echo   COMPILING QUEUE PROGRAM (ALT 1)
echo ======================================
echo.

echo Compiling...
g++ queue.cpp main.cpp -o queue.exe

if exist queue.exe (
    echo.
    echo PROGRAM BERHASIL DICOMPILE
    echo ===========================
    echo.
    queue.exe
    echo.
    pause
) else (
    echo.
    echo GAGAL COMPILE!
    pause
)