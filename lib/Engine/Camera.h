#ifndef CAMERA_H
#define CAMERA_H

#include <Eigen/Core>

struct Camera{
    // Origin
    Eigen::Vector3d Eye;
    
    // Orthonormal basis vectors. -W is the direction we are looking. U & V are orthonormal to W. 
    // Think of this as our rotation! 
    Eigen::Vector3d u,v,w;

    // Focal Distance
    double fd;
    
    // Width & height of the view plane. Recall l,r,t,d as the edges 
    double width, height;
};


#endif 