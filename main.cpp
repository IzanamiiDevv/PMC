#include <iostream>
#include <cstring>
#include <string>
#include "incl/proj.man.h"
#include "incl/dotenv.h"
#include "incl/System.h"

const char* concat(const char* str1,const char* str2);

int main(){
    std::cout << PD::read();
}

const char* concat(const char* str1,const char* str2){
    
    size_t len = strlen(str1) + strlen(str2) + 1;
    char* result = new char[len];
    strcpy(result, str1);
    strcat(result, str2);
    delete[] result;
    return result;
}