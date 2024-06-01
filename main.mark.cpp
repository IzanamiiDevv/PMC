#include <iostream>
#include <string>
#include "incl/cli.h"
#include "incl/error.h"
#include "incl/proj.man.h"

int main(int argc, char* argv[]) {
    std::string prj = CLI::scan_string("-p" , argc, argv);
    std::string status = CLI::scan_string("-s" , argc, argv);

    if (prj == "" || status == "") {
        Error::onArgument("Empty Values");
        return 1;
    }

    if(status == "-ongoing" || status == "-finished" || status == "-unfinished") {

        bool finded = false;
        bool working = false;
        bool curr = false;
        std::string mode;

        auto data = PD::read();
        for(const auto& row : data) {
            if(row[2] == "ongoing") curr = true;
            if(prj == row[0]) {
                finded = true;
                mode = row[1];
                working = (row[2] ==  "ongoing");
            }
        }

        if(!finded) {
            Error::onRunTime("Project Name Does not Exist");
            return 1;
        }

        if(working){
            std::string response;
            bool loop = true;
            do {
                Error::onRunTime("This Project is Currently Ongoing do you want to change its Status?");
                std::cout << "(y/n): ";
                std::cin >> response;
                std::cout << std::endl;
                if(response == "y" || response == "n") loop = false;
            }while(loop);

            if(response != "y"){
                std::cout << "Project did not changed its status" << std::endl;
                return 0;
            };
        }

        if(curr && status == "-ongoing"){
            std::string response;
            bool loop = true;
            do {
                Error::onRunTime("Other Project is Currently Ongoing \n You cant have 2 Ongoing Projects \n Would you like to set the Current Ongoing Project to Finished?");
                std::cout << "(y/n): ";
                std::cin >> response;
                std::cout << std::endl;
                if(response == "y" || response == "n") loop = false;
            }while(loop);

            auto data = PD::read();

            for(const auto& row : data) {
                if(row[2] == "ongoing") {
                    std::string temp[2] = {row[0], row[1]};
                    PD::removeProject(row[0]);
                    PD::update(temp[0], temp[1], (response != "y") ? "unfinished" : "finished");
                }
            }
        }

        std::string stat;
        for(int i = 1; i < status.length(); i++) {
            stat += status[i];
        }

        PD::removeProject(prj);
        PD::update(prj, mode, stat);
        std::cout << "Project Succesfully Changed Status" << std::endl;

        return 0;
    }

    Error::onArgument("Unknown Status");
    return 1;
}