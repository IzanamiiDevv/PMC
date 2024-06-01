#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "incl/httplib.h"
#include "incl/cli.h"
#include "incl/error.h"
#include "incl/proj.man.h"

void printScan(std::string name, std::string mode, std::string status);
std::string read_file(const std::string &path);
void viewWeb(const char* query);


int main(int argc, char* argv[]) {
    std::string x = CLI::scan_string("-x", argc, argv);
    std::string y = CLI::scan_string("-y", argc, argv);

    if(x == "-y") {
        Error::onArgument("No View Argument");
        return 0;
    }
    if(x == "-web" && y == ""){
        viewWeb("");
        return 0;
    }
    if(x != "" && y == "-web"){
        viewWeb(x.c_str());
        return 0;
    }

    auto data = PD::read();
    if(x == "-cmd" && y == "") {
        for (const auto& row : data) {
            printScan(row[0], row[1], row[2]);
        }

        return 0;
    }
    if(x != "" && y == "-cmd") {
        bool isFind = false;

        for (const auto& row : data) {
            for (const auto& col : row) {
                if (col == x) {
                    isFind = true;
                    printScan(row[0], row[1], row[2]);
                }
            }
        }
        
        if (!isFind) {
            Error::onRunTime("Can't find query");
        }

        return 0;
    }

    Error::onArgument("No View Argument");
    return 0;
}

void viewWeb(const char* query){
    httplib::Server svr;

    svr.Get("/", [](const httplib::Request &req, httplib::Response &res) {
        std::string content = read_file("public/index.html");
        if (!content.empty()) {
            res.set_content(content, "text/html");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    svr.Get("/style.css", [](const httplib::Request &, httplib::Response &res) {
        std::string content = read_file("public/style.css");
        if (!content.empty()) {
            res.set_content(content, "text/css");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    svr.Get("/main.js", [](const httplib::Request &, httplib::Response &res) {
        std::string content = read_file("public/main.js");
        if (!content.empty()) {
            res.set_content(content, "application/javascript");
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });

    if(query == "") {
        std::cout << "Click this Link http://localhost:8080" << std::endl;
    }else {
        std::cout << "Click this Link http://localhost:8080" << "?" << query << std::endl;
    }
    svr.listen("localhost", 8080);
}

void printScan(std::string name, std::string mode, std::string status) {
    std::cout << "Project Name: " << name << std::endl;
    std::cout << "Project Mode: " << mode << std::endl;
    std::cout << "Project Status: " << status << std::endl;
    std::cout << "===========================" << std::endl;
}

std::string read_file(const std::string &path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
