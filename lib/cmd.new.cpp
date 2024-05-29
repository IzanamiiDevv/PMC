#include <iostream>
#include <cstring>
#include <exception>
#include "../incl/cmd.new.h"
#include "../incl/System.h"
#include "../incl/error.h"


namespace ACTION_NEW
{
    void test() {
        std::cout << "Hello World";
    }

    void create_github(const char* arg) {
        const char* command = "cd projects && git clone ";

        size_t cmdlen = strlen(command);
        size_t arglen = strlen(arg);

        char* cmd = new char[cmdlen + arglen + 1];

        strcpy(cmd , command);
        strcat(cmd, arg);

        try
        {
            std::string result = System::exec(cmd);
            std::cout << result << std::endl;
            std::cout << "Test" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }

    void create_local(const char* arg) {

    }
}
