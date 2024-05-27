@echo off
setlocal enabledelayedexpansion

set /a sum=0

rem Loop through all the arguments
:loop
if "%~1" neq "" (
    rem Check if the argument starts with "-x"
    if /i "%~1"=="-x" (
        set x=%2
        shift
        shift
    ) else (
        rem Check if the argument starts with "-y"
        if /i "%~1"=="-y" (
            set y=%2
            shift
            shift
        ) else (
            rem If argument doesn't match any option, exit the loop
            goto :endloop
        )
    )
    goto :loop
)

:endloop
rem Calculate the sum of x and y
set /a sum=x+y

cd C:\Users\rosar\Documents\pmc && pmcb

endlocal
