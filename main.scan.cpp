#include <iostream>
#include "incl/cli.h"
#include "incl/error.h"
#include "incl/proj.man.h"

void printScan(std::string name, std::string mode, std::string status);

int main(int argc, char* argv[]) {

    std::string query = CLI::scan_string("-w", argc, argv);

    auto data = PD::read();

    if(query != "") {
        bool isFind = false;
        for(const auto& row : data) {
            for(const auto& col : row) {
                if(col == query) {
                    isFind = true;
                    printScan(row[0], row[1], row[2]);
                }
            }
        }
        if(!isFind){
            Error::onRunTime("Cant Find Query");
        }

        return 0;
    }

    for(const auto& row : data) {
        printScan(row[0], row[1], row[2]);
    }

    return 0;
}

void printScan(std::string name, std::string mode, std::string status) {
    std::cout << "Project Name: " << name << std::endl;
    std::cout << "Project Mode: " << mode << std::endl;
    std::cout << "Project Status: " << status << std::endl;
    std::cout << "===========================" << std::endl;
}