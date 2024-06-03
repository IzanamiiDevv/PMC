#include <iostream>
#include <string>
#include "incl/cli.h"
#include "incl/error.h"

int hash_string(std::string txt);

int main(int argc, char* argv[]) {

    std::string cmd = CLI::scan_string("-on", argc, argv);
    int Icmd = hash_string(cmd);

    if(cmd != "") {

        switch (Icmd)
        {
        case 427 :
            std::cout << "Command: mark" << std::endl;
            std::cout << "Flags: " << std::endl;
            std::cout << "  - -ongoing: Mark the project as ongoing" << std::endl;
            std::cout << "  - -finished: Mark the project as finished" << std::endl;
            std::cout << "  - -unfinished: Mark the project as unfinished" << std::endl;
            std::cout << "Syntax: mark [project name] [flag]" << std::endl;
            std::cout << "Description: Change the project status" << std::endl;
            break;

        case 421 :
            std::cout << "Command: scan" << std::endl;
            std::cout << "Flags: " << std::endl;
            std::cout << "  - -cmd: Display the project data on the command line" << std::endl;
            std::cout << "  - -web: Display the project data on the website" << std::endl;
            std::cout << "Syntax: " << std::endl;
            std::cout << "  - scan [flag]" << std::endl;
            std::cout << "  - scan [query] [flag]" << std::endl;
            std::cout << "Description: Display the project data on the command line or website based on the given query and flags" << std::endl;
            break;

        case 309 :
            std::cout << "Command: del" << std::endl;
            std::cout << "Flags: none" << std::endl;
            std::cout << "Syntax: del [project name]" << std::endl;
            std::cout << "Description: Delete the project folder" << std::endl;
            break;

        case 411 :
            std::cout << "Command: code" << std::endl;
            std::cout << "Flags: none" << std::endl;
            std::cout << "Syntax: " << std::endl;
            std::cout << "  - code" << std::endl;
            std::cout << "  - code [project name]" << std::endl;
            std::cout << "Description: Open the VSCode editor of the current ongoing or specified project" << std::endl;
            break;

        case 330 :
            std::cout << "Command: new" << std::endl;
            std::cout << "Flags: " << std::endl;
            std::cout << "  - -local: Create a new project typed locally" << std::endl;
            std::cout << "  - -github: Create a new project typed GitHub" << std::endl;
            std::cout << "Syntax: new [flag] [project name]" << std::endl;
            std::cout << "Description: Create a new project folder" << std::endl;
            break;
    
        }

        Error::onRunTime("Invalid Command");
        return 0;
    }

    std::cout << "Commands:" << std::endl;
    std::cout << "  - mark" << std::endl;
    std::cout << "  - scan" << std::endl;
    std::cout << "  - del" << std::endl;
    std::cout << "  - code" << std::endl;
    std::cout << "  - new" << std::endl;


    std::cout << std::endl;

    std::cout << "Command: mark" << std::endl;
    std::cout << "Flags: " << std::endl;
    std::cout << "  - -ongoing: Mark the project as ongoing" << std::endl;
    std::cout << "  - -finished: Mark the project as finished" << std::endl;
    std::cout << "  - -unfinished: Mark the project as unfinished" << std::endl;
    std::cout << "Syntax: mark [project name] [flag]" << std::endl;
    std::cout << "Description: Change the project status" << std::endl;


    std::cout << std::endl;

    std::cout << "Command: scan" << std::endl;
    std::cout << "Flags: " << std::endl;
    std::cout << "  - -cmd: Display the project data on the command line" << std::endl;
    std::cout << "  - -web: Display the project data on the website" << std::endl;
    std::cout << "Syntax: " << std::endl;
    std::cout << "  - scan [flag]" << std::endl;
    std::cout << "  - scan [query] [flag]" << std::endl;
    std::cout << "Description: Display the project data on the command line or website based on the given query and flags" << std::endl;


    std::cout << std::endl;

    std::cout << "Command: del" << std::endl;
    std::cout << "Flags: none" << std::endl;
    std::cout << "Syntax: del [project name]" << std::endl;
    std::cout << "Description: Delete the project folder" << std::endl;


    std::cout << std::endl;

    std::cout << "Command: code" << std::endl;
    std::cout << "Flags: none" << std::endl;
    std::cout << "Syntax: " << std::endl;
    std::cout << "  - code" << std::endl;
    std::cout << "  - code [project name]" << std::endl;
    std::cout << "Description: Open the VSCode editor of the current ongoing or specified project" << std::endl;


    std::cout << std::endl;

    std::cout << "Command: new" << std::endl;
    std::cout << "Flags: " << std::endl;
    std::cout << "  - -local: Create a new project typed locally" << std::endl;
    std::cout << "  - -github: Create a new project typed GitHub" << std::endl;
    std::cout << "Syntax: new [flag] [project name]" << std::endl;
    std::cout << "Description: Create a new project folder" << std::endl;


    return 0;
}

int hash_string(std::string txt){
    int res = 0;
    for(int i = 0; i < txt.size(); i++) {
        res += (int)txt[i];
    }

    return res;
}