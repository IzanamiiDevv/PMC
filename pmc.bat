@echo off
setlocal


cd C:\Users\rosar\Documents\pmc

if "%1"=="h" (
    pmc.h -on %2
)

if "%1"=="help" (
    pmc.h -on %2
)

if "%1"=="goto" (
    echo %2
)

if "%1"=="scan" (
    echo %2
)

if "%1"=="del" (
    echo %2
)

if "%1"=="code" (
    echo %2
)


endlocal