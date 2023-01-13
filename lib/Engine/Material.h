#ifndef MATERIAL_H
#define MATERIAL_H

#include <Eigen/Core> 

typedef Eigen::Vector<uint8_t,3> RGB;

struct Material{

    RGB rgb;
    
    
    
    // Eventually: pointer to some texture mat object here


} ;


#endif