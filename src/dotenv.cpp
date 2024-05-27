#include <iostream>
#include <fstream>
#include <string>
#include "../incl/dotenv.h"

namespace ENV {
    void change(std::string txt){
        std::ofstream outfile(".env");
        if(outfile.is_open()) {
            outfile << "PATH=" << txt;
            outfile.close();
        } else {
            std::cerr << "Error On Writing File" << '\n';
        }
    }

    std::string read(){
        std::string env = "";
        std::string data = "";
        std::ifstream infile(".env");
        bool isRead = false;

        if(infile.is_open()) {
        std::string line;
        while(std::getline(infile,line)) {
            if(!isRead){
                env = line;
            }
            isRead = true;
        }
        infile.close();
        }else {
            std::cerr << "Error Reading the ENV" << std::endl;
        }

        for(int i = 5; i < env.size(); i++) {
            data += env[i];
        }

        return data;
    }
}