#pragma once

#include <string>
#include <vector>
#include <Eigen\Dense>


int writeFile(std::string name,std::string content);

std::string getTime();

class PAM{
    protected:
        std::string     header;
        uint32_t        width;
        uint32_t        height;
        uint16_t        max;
        Eigen::Matrix<uint8_t,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> data;
        
    public:
        PAM(std::string s, uint32_t w, uint32_t h, uint16_t m,const Eigen::Matrix<uint8_t,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> d);
        //PAM(std::string s, uint32_t w, uint32_t h, uint16_t m, Eigen::MatrixXd d);
        virtual int generate();
        //static int generate(const std::string& pgmString);
        //static int generate(const Eigen::MatrixXd& pgmVector,int sizeX, int sizeY, int max);
        virtual ~PAM();
};


class PGM : public PAM{
    private: 
    public:
        PGM(uint32_t w, uint32_t h, uint16_t m,const Eigen::Matrix<uint8_t,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> d) : PAM(std::string("P2"),w,h,m,d){};
        // Virtual
        int generate();
        // static as long as claimed here 
        // TODO: Implement
        static int generateFromString(std::string dataString, int width, int height, int max);
        static int generate(const Eigen::Matrix<uint8_t,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor>& ,int sizeX, int sizeY, int max);


};


class PPM : public PAM{
    public:
        PPM(uint32_t w, uint32_t h, uint16_t m,const Eigen::Matrix<uint8_t,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> d) : PAM(std::string("P3"),w,h,m,d){};

        int generate();
        
        static int generateFromRaster(uint32_t w, uint32_t h, uint16_t m, Eigen::Matrix<uint8_t,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> d);

};
