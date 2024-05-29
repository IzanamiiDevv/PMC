#include <iostream>
#include "../incl/error.h"

namespace Error
{
    void onArgument(const char* txt) {
        std::cerr << "Argument Error: " << txt << std::endl;
    }
    
    void onExecution(const char* txt) {
        std::cerr << "Execution Error: " << txt << std::endl;
    }
}