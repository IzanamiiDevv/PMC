#include <iostream>
#include <string>
#include "incl/cli.h"
#include "incl/cmd.new.h"

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
        std::cerr << "Error: Empty Arguments Program cant Execute" << std::endl;
        return 0;
    }

    if(mode == 0) {
        std::cerr << "Error: Project mode not Initialized" << std::endl;
        return 1;
    }

    if(project == "") {
        std::cerr << "Error: Empty Project Name is Not Valid" << std::endl;
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