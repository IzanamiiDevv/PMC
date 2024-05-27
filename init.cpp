#include <iostream>
#include "incl/cli.h"

int main(int argc, char* argv[]){
    std::string env = CLI::scan_string("path",argc,argv);
    std::cout << env;
}