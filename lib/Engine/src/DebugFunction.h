#pragma once
#ifdef DEBUG
#include <string>
#include <iostream>
void DBGPrint(std::string s){
    std::cout << s << std::endl;
}

#else

void DBGPrint(...){

}

#endif

