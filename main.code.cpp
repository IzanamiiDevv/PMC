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
        Error::onRunTime("Do You Want to Execute the Command Prompt for this Project?");
        std::cout << "(y/n): ";
        std::cin >> response;
        std::cout << std::endl;

        if(response == "y" || response == "n") loop = false;
    }while(loop);

    try
    {
        std::string result = System::exec(cmd);
        std::cout << "Project Succesfully Opened" << std::endl;
        if(response == "y") {
            const char* command = "cd projects/";
            const char* seccommand = " && start cmd";

            size_t cmdslen = strlen(command);
            size_t arglen = strlen(project.c_str());

            char* cmds = new char[cmdslen + arglen + 1];

            strcpy(cmds , command);
            strcat(cmds, project.c_str());

            size_t cmddlen = strlen(cmds);
            size_t seccommandlen = strlen(seccommand);

            char* cmdd = new char[cmddlen + seccommandlen + 1];

            strcpy(cmdd, cmds);
            strcat(cmdd, seccommand);

            std::string result = System::exec(cmdd);
        }
    }
    catch(const std::exception& e)
    {
        Error::onExecution(e.what());
    }
    
}

void run_project(const char* project, std::vector<std::vector<std::string>> data) {
    std::vector<std::string> existng_project;
    bool project_exist = false;
    bool another_exist = false;
    std::string project_type;

    for(const auto& row : data) {
        if(row[2] == "ongoing") existng_project = {row[0], row[1]};
        if(row[0] == project) {
            project_exist = true;
            project_type = row[1];
        }
    }

    if(existng_project[0] != project) another_exist = true;

    if(!project_exist) {
        Error::onExecution("Cant Find The Project");
        return;
    }

    const char* command = "cd projects && code ";

    if(another_exist) {
        std::cout << "Another Project Existed" << std::endl;

        std::string response;
        bool loop = true;

        do {
            Error::onRunTime("Another Project Currently Exist Would you Like to Change it to Finished?");
            std::cout << "(y/n): ";
            std::cin >> response;
            std::cout << std::endl;

            if(response == "y" || response == "n") loop = false;
        }while(loop);

        PD::removeProject(existng_project[0]);

        if(response == "y") {
            PD::update(existng_project[0], existng_project[1], "finished");
        }else {
            PD::update(existng_project[0], existng_project[1], "unfinished");
        }
    }

    size_t cmdlen = strlen(command);
    size_t arglen = strlen(project);

    char* cmd = new char[cmdlen + arglen + 1];

    strcpy(cmd , command);
    strcat(cmd, project);

    std::string response;
    bool loop = true;

    do {
        Error::onRunTime("Do You Want to Execute the Command Prompt for this Project?");
        std::cout << "(y/n): ";
        std::cin >> response;
        std::cout << std::endl;

        if(response == "y" || response == "n") loop = false;
    }while(loop);

    try
    {
        std::string result = System::exec(cmd);

        PD::removeProject(project);
        PD::update(project, project_type, "ongoing");

        std::cout << "Project Succesfully Opened" << std::endl;

        if(response == "y") {
            const char* command = "cd projects/";
            const char* seccommand = " && start cmd";

            size_t cmdslen = strlen(command);
            size_t arglen = strlen(project);

            char* cmds = new char[cmdslen + arglen + 1];

            strcpy(cmds , command);
            strcat(cmds, project);

            size_t cmddlen = strlen(cmds);
            size_t seccommandlen = strlen(seccommand);

            char* cmdd = new char[cmddlen + seccommandlen + 1];

            strcpy(cmdd, cmds);
            strcat(cmdd, seccommand);

            std::string result = System::exec(cmdd);
        }
    }
    catch(const std::exception& e)
    {
        Error::onExecution(e.what());
    }
}