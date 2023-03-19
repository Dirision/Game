#include "PAM.h"
#include <string>
#include <Eigen\Dense>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctime>
#include <sstream>
#include <iomanip>


Eigen::IOFormat matrixRaster(Eigen::StreamPrecision,
                                Eigen::DontAlignCols,
                                " ","","","\n","","");

int writeFile(std::string name,std::string content, int s = 0){
    //std::cout << name << std::endl;
    //std::cout << content;
    if (s==1){
        std::cout << content;
    } else {
        std::ofstream f(name);
        f << content;
        f.close();
        std::cout << "File written: " << name << std::endl;
    }
    return 0;
}

std::string getTime(){
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm,"%H-%M-%S");
    return oss.str(); 
}



PAM::PAM(std::string s, uint32_t w, uint32_t h, uint16_t m, Eigen::Matrix<uint8_t,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> d){
            header  = s;
            width   = w;
            height  = h;
            max     = m;
            data    = d;
};
int PAM::generate(){

    return 0;
};
PAM::~PAM(){};


int PGM::generate(){

    return 0;
};



// STATIC: per header
int PGM::generateFromString(std::string dataString, int width, int height, int max){
            std::string fileName    = getTime()+".pgm";
            std::string fText       = "P2\n"+std::to_string(width)+
                                    " "+std::to_string(height)+"\n"+
                                    std::to_string(max)+ "\n"+dataString;
            writeFile(fileName,fText,0);
            return 0;
        };

/*
*   Takes raster passed to it, and dumps it to file. 
*   Params w = width, h = height, m = max color value (0-2^8), d = raster to draw
*/ 
int PPM::generateFromRaster(const uint32_t w,const uint32_t h, uint16_t m,const Eigen::Matrix<uint8_t,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> d){
    std::string fileName    =   getTime()+".ppm";
    std::stringstream fText;
    fText << "P3\n"+std::to_string(w)+" "+std::to_string(h)+"\n"+
                std::to_string(m)+ "\n" << d.format(matrixRaster);
    // Set flag = 0 below 
    writeFile(fileName,fText.str(),0);
    return 0; 
};

