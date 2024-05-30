#include <iostream>
#include <cstring>
#include <exception>
#include <string>
#include "../incl/cmd.new.h"
#include "../incl/System.h"
#include "../incl/error.h"
#include "../incl/proj.man.h"


namespace ACTION_NEW
{
    void test() {
        std::cout << "Hello World";
    }

    void create_github(const char* arg) {
        const char* command = "cd projects && git clone ";

        size_t cmdlen = strlen(command);
        size_t arglen = strlen(arg);

        char* cmd = new char[cmdlen + arglen + 1];

        strcpy(cmd , command);
        strcat(cmd, arg);
        
        std::string temp;
        for(int i = arglen; i > 0; i--) {
            if(arg[i] == '/') break;
            temp += arg[i];
        }

        std::string projectName;
        for(int i = temp.size() - 1; i > 0; i--) {
            if(temp[i] == '.') break;
            projectName += temp[i];
        }

        ACTION_NEW::new_project(projectName, "github");

        try
        {
            std::string result = System::exec(cmd);
            std::cout << result << std::endl;
        }
        catch(const std::exception& e)
        {
            Error::onExecution(e.what());
        }
    }

    void create_local(const char* arg) {
        const char* command = "cd projects && mkdir ";

        size_t cmdlen = strlen(command);
        size_t arglen = strlen(arg);

        char* cmd = new char[cmdlen + arglen + 1];

        strcpy(cmd , command);
        strcat(cmd, arg);

        ACTION_NEW::new_project(arg, "local");

        try
        {
            std::string result = System::exec(cmd);
            std::cout << result << std::endl;
        }
        catch(const std::exception& e)
        {
            Error::onExecution(e.what());
        }

    }

    void new_project(std::string name, std::string mode) {
        auto data = PD::read();
        std::string prevname;
        std::string prevmode;

        for (const auto& row : data) {
            if(row[2] == "ongoing") {
                prevname = row[0];
                prevmode = row[1];
            }
        }
        PD::removeStatus("ongoing");

        if(prevname != "") {
            std::string response;
            bool loop = true;
            do {
                Error::onRunTime("There is Current Project Ongoing Would you like to mark it as Finished?");
                std::cout << "(y/n): ";
                std::cin >> response;
                std::cout << std::endl;
                if(response == "y" || response == "n") loop = false;
            }while(loop);

            if(response == "y") {
                PD::update(prevname, prevmode, "finished");
            }else {
                PD::update(prevname, prevmode, "unfinished");
            }
        }

        PD::update(name, mode, "ongoing");
    }
}