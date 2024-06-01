#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "incl/httplib.h"
#include "incl/cli.h"
#include "incl/error.h"
#include "incl/proj.man.h"

void printScan(std::string name, std::string mode, std::string status);
std::string read_file(const std::string &path);
void viewWeb(const char* query);
void calcColWidth(const std::vector<std::vector<std::string>>& data, std::vector<size_t>& widths);
void displayTable(const std::vector<std::vector<std::string>>& data);


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
        std::vector<std::vector<std::string>> table = {
            {"name:", "type:", "status:"}
        };

        for (const auto& row : data) {
            table.push_back({row[0],row[1],row[2]});
        }
        
        if (data.size() == 0) {
            Error::onRunTime("You have no Projects");
            return 0;
        }

        displayTable(table);

        return 0;
    }
    if(x != "" && y == "-cmd") {
        bool isFind = false;

        std::vector<std::vector<std::string>> table = {
            {"name:", "type:", "status:"}
        };

        for (const auto& row : data) {
            for (const auto& col : row) {
                if (col == x) {
                    isFind = true;
                    table.push_back({row[0],row[1],row[2]});
                }
            }
        }
        
        if (!isFind) {
            Error::onRunTime("Can't find query there is no Output");
            return 0;
        }

        displayTable(table);

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

void calcColWidth(const std::vector<std::vector<std::string>>& data, std::vector<size_t>& widths) {
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (row[i].length() > widths[i]) {
                widths[i] = row[i].length();
            }
        }
    }
}

void displayTable(const std::vector<std::vector<std::string>>& data) {
    if (data.empty()) return;

    std::vector<size_t> widths(data[0].size(), 0);
    calcColWidth(data, widths);

    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            std::cout << std::left << std::setw(widths[i] + 5) << row[i];
            if (i < row.size() - 1) {
                std::cout << ": ";
            }
        }
        std::cout << std::endl;
    }
}

std::string read_file(const std::string &path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
