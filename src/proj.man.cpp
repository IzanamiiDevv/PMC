#include <iostream>
#include <fstream>
#include "./../incl/proj.man.h"


//Project Data
namespace PD {
    std::string read(){
        std::string data = "";
        std::ifstream infile("project.data.txt");

        if(infile.is_open()) {
        std::string line;
        while(std::getline(infile,line)) {
            data += line + '\n';
        }
        infile.close();
        }else {
            std::cerr << "Error Reading the File" << std::endl;
        }

        return data;
    }

    std::string deleteData(){
        std::string data = "";
        std::ifstream infile("project.data.txt");

        if(infile.is_open()) {
        std::string line;
        while(std::getline(infile,line)) {
            data += line + '\n';
        }
        infile.close();
        }else {
            std::cerr << "Error Reading the File" << std::endl;
        }

        return data;
    }
}