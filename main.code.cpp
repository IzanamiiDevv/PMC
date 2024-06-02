#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <exception>
#include "incl/cli.h"
#include "incl/System.h"
#include "incl/proj.man.h"
#include "incl/error.h"

void run_current(std::vector<std::vector<std::string>> data);
void run_project(const char* project, std::vector<std::vector<std::string>> data);

int main(int argc, char* argv[]) {
    std::string prj = CLI::scan_string("-p", argc, argv);

    std::vector<std::vector<std::string>> data = PD::read();

    if(prj.empty()) {
        run_current(data);
        return 0;
    }
    run_project(prj.c_str(), data);
    return 0;
}

void run_current(std::vector<std::vector<std::string>> data) {
    std::string project;
    const char* command = "cd projects && code ";

    for(const auto& row : data) {
        if(row[2] == "ongoing") {
            project = row[0];
            break;
        }
    }

    if(project.empty()) {
        Error::onRunTime("No Project is Currently Ongoing");
        return;
    }

    size_t cmdlen = strlen(command);
    size_t arglen = strlen(project.c_str());

    char* cmd = new char[cmdlen + arglen + 1];

    strcpy(cmd , command);
    strcat(cmd, project.c_str());

    std::string response;
    bool loop = true;

    do {
        Error::onRunTime("Other Project is Currently Ongoing \n You cant have 2 Ongoing Projects \n Would you like to set the Current Ongoing Project to Finished?");
        std::cout << "(y/n): ";
        std::cin >> response;
        std::cout << std::endl;
        if(response == "y" || response == "n") loop = false;
    }while(loop);

    try
    {
        if(response == "y") {
            const char* command = "";

            size_t cmdlen = strlen(command);
            size_t arglen = strlen(project.c_str());

            char* cmd = new char[cmdlen + arglen + 1];

            strcpy(cmd , command);
            strcat(cmd, project.c_str());

            System::exec(cmd);
        }
        System::exec(cmd);
        std::cout << "Project Succesfully Opened" << std::endl;
    }
    catch(const std::exception& e)
    {
        Error::onExecution(e.what());
    }
    
}

void run_project(const char* project, std::vector<std::vector<std::string>> data) {

}