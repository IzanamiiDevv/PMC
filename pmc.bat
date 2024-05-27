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
            set mode=0
            shift
        ) else (
            goto :endloop
        )
        goto :loop
    )

    :endloop
    pmc.n -param %mode% -proj %project%
)

endlocal