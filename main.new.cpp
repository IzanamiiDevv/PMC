#include <iostream>
#include <string>
#include "incl/cli.h"

int main(int argc, char* argv[]) {
    int mode = CLI::scan_int("-param", argc, argv);
    std::string project =  CLI::scan_string("-proj", argc, argv);

    if(project == "") {
        std::cerr << "Error: Empty Project Name is Not Valid" << std::endl;
        return 1;
    }

    switch (mode)
    {
    case 0:
        std::cout << "NEW LOCAL PROJECT";
        break;
    case 1:
        std::cout << "NEW GITHUB PROJECT";
        break;
    }

    return 0;
}