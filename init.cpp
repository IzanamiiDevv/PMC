#include <iostream>
#include "incl/cli.h"
#include "incl/dotenv.h"

int main(int argc, char* argv[]){
    std::string env = CLI::scan_string("path",argc,argv);
    
    ENV::change(env);
}