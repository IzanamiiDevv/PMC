#include <iostream>
#include "incl/cli.h"
#include "incl/proj.man.h"
#include "incl/error.h"

int main(int argc, char* argv[]) {
    std::string name = CLI::scan_string("-prj", argc, argv);

    if(name != "") {
        auto data = PD::read();
        bool isHere = false;
        for (const auto& row : data) {
            if(row[0] == name) {
                isHere = true;
            }
        }

        if(!isHere){
            Error::onExecution("Project name not found");
            return 1;
        }

        PD::removeProject(name);
        std::cout << "Project Successfully Deleted" << std::endl;
        return 0;
    }

    PD::removeStatus("finished");
    std::cout << "Projects Successfully Deleted" << std::endl;
    return 0;
}