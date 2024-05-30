@echo off

g++ -shared -o error.dll lib/error.cpp -Wl,--out-implib,liberror.a
g++ -shared -o cmdnew.dll lib/cmd.new.cpp lib/System.cpp src/*.cpp -L. -lerror -Wl,--out-implib,libcmdnew.a
g++ -o pmc.h.exe main.help.cpp src/*.cpp -L. -lerror
g++ -o pmc.n.exe main.new.cpp src/*.cpp -L. -lcmdnew -lerror
g++ -o pmc.del.exe main.del.cpp src/*.cpp -L. -lerror
g++ -o pmc.scan.exe main.scan.cpp src/*.cpp -L. -lerror