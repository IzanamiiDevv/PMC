@echo off

g++ -o pmc.h.exe  main.help.cpp src/*.cpp && g++ -shared -o cmdnew.dll lib/cmd.new.cpp lib/System.cpp src/*.cpp -Wl,--out-implib,libcmdnew.a && g++ -o pmc.n.exe main.new.cpp src/*.cpp -L . -l cmdnew && g++ -o pmc.del.exe  main.del.cpp src/*.cpp