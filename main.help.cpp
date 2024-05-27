#include <iostream>
#include "incl/cli.h"

int main(int argc, char* argv[]) {

    std::string cmd = CLI::scan_string("-on", argc, argv);

    if(cmd != "") {
        
        std::cout << "HELP" << cmd;

        return 0;
    }
    
    std::cout << "HELP";

    return 0;
}