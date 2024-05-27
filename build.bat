@echo off

g++ -o pmc.h.exe  main.help.cpp lib/*.cpp && g++ -o pmc.n.exe  main.new.cpp lib/*.cpp src/*.cpp