#include <iostream>
#include <string>
#include "incl/cli.h"

int hash_string(std::string txt);

int main(int argc, char* argv[]) {

    std::string cmd = CLI::scan_string("-on", argc, argv);
    int Icmd = hash_string(cmd);

    if(cmd != "") {

        switch (Icmd)
        {
        case 441 :
            std::cout << "HELP goto" << '\n';
            break;

        case 421 :
            std::cout << "HELP scan" << '\n';
            break;

        case 309 :
            std::cout << "HELP del" << '\n';
            break;

        case 411 :
            std::cout << "HELP code" << '\n';
            break;

        case 330 :
            std::cout << "HELP new" << '\n';
            break;
    
        }
        return 0;
    }
    
    std::cout << "HELP" << '\n';

    return 0;
}

int hash_string(std::string txt){
    int res = 0;
    for(int i = 0; i < txt.size(); i++) {
        res += (int)txt[i];
    }

    return res;
}