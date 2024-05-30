#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "./../incl/proj.man.h"
#include "../incl/error.h"

namespace PD {

    std::vector<std::vector<std::string>> read() {
        std::vector<std::vector<std::string>> data;
        std::ifstream infile("project.data.txt");

        if(infile.is_open()) {
            std::string line;
            while(std::getline(infile, line)) {
                std::vector<std::string> row;
                std::stringstream ss(line);
                std::string cell;

                while (std::getline(ss, cell, ';')) {
                    row.push_back(cell);
                }
                data.push_back(row);
            }
            infile.close();
        } else {
            std::cerr << "Error reading the file" << std::endl;
        }

        return data;
    }

    void write(const std::vector<std::vector<std::string>>& data) {
        std::ofstream outfile("project.data.txt");

        if(outfile.is_open()) {
            for (const auto& row : data) {
                for (size_t i = 0; i < row.size(); ++i) {
                    outfile << row[i];
                    if (i < row.size() - 1) {
                        outfile << ";";
                    }
                }
                outfile << "\n";
            }
            outfile.close();
        } else {
            std::cerr << "Error writing to the file" << std::endl;
        }
    }

    void update(const std::string& project, const std::string& mode, const std::string& status) {
        auto data = read();
        bool found = false;

        for (auto& row : data) {
            if (row[0] == project) {
                row[1] = mode;
                row[2] = status;
                found = true;
                break;
            }
        }

        if (!found) {
            data.push_back({project, mode, status});
        }

        write(data);
    }

    void removeProject(const std::string& project) {
        auto data = read();
        data.erase(std::remove_if(data.begin(), data.end(), [&project](const std::vector<std::string>& row) {
            return row[0] == project;
        }), data.end());

        write(data);
    }

    void removeStatus(const std::string& status) {
        auto data = read();
        data.erase(std::remove_if(data.begin(), data.end(), [&status](const std::vector<std::string>& row) {
            return row[2] == status;
        }), data.end());

        write(data);
    }
}

/*
int main() {
    // Example usage:
    auto data = PD::read();
    for (const auto& row : data) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    PD::update("NewProject", "github", "ongoing");
    PD::removeProject("Test1");
    PD::removeStatus("finished");

    return 0;
}

*/