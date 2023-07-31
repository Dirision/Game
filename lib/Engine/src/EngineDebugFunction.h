#ifndef ENGINEDEBUGFUNCTION_H
#define ENGINEDEBUGFUNCTION_H
#ifdef DEBUG

#include <string>
#include <iostream>
#include <ctime>


void DBGPrint(std::string s);

#else

void DBGPrint(...){

}
#endif
#endif

