#include <iostream>
#include <cstring>
#include <exception>
#include <string>
#include "incl/cli.h"
#include "incl/proj.man.h"
#include "incl/error.h"
#include "incl/System.h"

int main(int argc, char* argv[]) {
    std::string name = CLI::scan_string("-prj", argc, argv);

    const char* command = "cd projects && rmdir /S /Q ";

    if(name != "") {
        auto data = PD::read();
        bool isHere = false;
        std::string status;
        for (const auto& row : data) {
            if(row[0] == name) {
                isHere = true;
                status = row[2];
            }
        }

        if(!isHere){
            Error::onExecution("Project name not found");
            return 1;
        }

        if(status == "ongoing") {
            std::string response;
            bool loop = true;
            do {
                Error::onRunTime("This Project is Currently Ongoing Would you Proceed to Deletion?");
                std::cout << "(y/n): ";
                std::cin >> response;
                std::cout << std::endl;
                if(response == "y" || response == "n") loop = false;
            }while(loop);

            if(response != "y"){
                std::cout << "Project did not Deleted" << std::endl;
                return 0;
            };
        }

        size_t cmdlen = strlen(command);
        size_t arglen = strlen(name.c_str());

        char* cmd = new char[cmdlen + arglen + 1];

        strcpy(cmd , command);
        strcat(cmd, name.c_str());

        try
        {
            std::string result = System::exec(cmd);
            std::cout << result << std::endl;
        }
        catch(const std::exception& e)
        {
            Error::onExecution(e.what());
        }

        PD::removeProject(name);
        std::cout << "Project Successfully Deleted" << std::endl;
        return 0;
    }

    PD::removeStatus("finished");
    std::cout << "Projects Successfully Deleted" << std::endl;
    return 0;
}