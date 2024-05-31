#include <iostream>
#include <string>
#include "incl/cli.h"
#include "incl/cmd.new.h"
#include "incl/error.h"

int main(int argc, char* argv[]) {
    int mode;
    std::string project;

    try
    {
        mode = CLI::scan_int("-param", argc, argv);
        project =  CLI::scan_string("-proj", argc, argv);
    }
    catch(const std::exception& e)
    {
        Error::onArgument("Empty Values");
        return 1;
    }

    if(mode == 0) {
        Error::onArgument("Project mode not Initialized");
        return 1;
    }

    if(project == "") {
        Error::onArgument("Empty Project Name is Not Valid");
        return 1;
    }

    switch (mode)
    {
    case 2:
        std::cout << "NEW LOCAL PROJECT" << '\n';
        ACTION_NEW::create_local(project.c_str());
        break;
    case 1:
        std::cout << "NEW GITHUB PROJECT" << '\n';
        ACTION_NEW::create_github(project.c_str());
        break;
    }

    return 0;
}