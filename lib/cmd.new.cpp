#include <iostream>
#include <cstring>
#include <exception>
#include "./../incl/cmd.new.h"
#include "./../incl/System.h"


namespace ACTION_NEW
{
    void test() {
        std::cout << "Hello World";
    }

    void create_github(const char* arg) {
        try
        {
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }

    void create_local(const char* arg) {

    }
}
