#pragma once
#ifdef DEBUG

#include <string>
#include <iostream>
#include <ctime>


void DBGPrint(std::string s){

    std::time_t t = std::time(0);
    std::cout <<  std::localtime(&t)->tm_hour << ":"
    << std::localtime(&t)->tm_min
    << ": "
    << s
    << std::endl;
}

#else

void DBGPrint(...){

}

#endif

