@echo off

::::::::::::::::::::::::::::::::::::::::
:: Project Name:    Project Manager CLI
:: Author:          IzanamiiDevv
:: Licens:          MIT
:: Copyright (c) 2024 IzanamiiDevv. All rights reserved.
::::::::::::::::::::::::::::::::::::::::

:: Start
setlocal

::::::::::::::::::::::::::::::::::::::::

:: Set Path to the Projects Directory
cd C:\Users\rosar\Documents\pmc

::::::::::::::::::::::::::::::::::::::::

:: Help
if "%1"=="h" (
    pmc.h -on %2
    exit /b
)

if "%1"=="help" (
    pmc.h -on %2
    exit /b
)

::::::::::::::::::::::::::::::::::::::::

:: Go to
if "%1"=="goto" (
    echo %2
    exit /b
)

::::::::::::::::::::::::::::::::::::::::

:: Mark
if "%1"=="mark" (
    pmc.mark -p %2 -s %3
    exit /b
)

::::::::::::::::::::::::::::::::::::::::

:: Scan
if "%1"=="scan" (
    pmc.scan -x %2 -y %3
    exit /b
)

::::::::::::::::::::::::::::::::::::::::

:: Delete
if "%1"=="del" (
    pmc.del -prj %2
    exit /b
)

::::::::::::::::::::::::::::::::::::::::

:: Code
if "%1"=="code" (
    echo %2
    exit /b
)

::::::::::::::::::::::::::::::::::::::::

:: New
if "%1"=="new" (
    set mode=0
    set project=%3
    shift
    shift

    :loop
    if "%~2" neq "" (
        if /i "%~2"=="-github" (
            set mode=1
            shift
        ) else if /i "%~2"=="-local" (
            set mode=2
            shift
        ) else (
            goto :endloop
        )
        goto :loop
    )

    :endloop
    pmc.n -param %mode% -proj %project%
    exit /b
)

::::::::::::::::::::::::::::::::::::::::

:: End
endlocal