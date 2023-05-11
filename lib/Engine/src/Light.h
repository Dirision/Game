#ifndef LIGHT_H
#define LIGHT_H

#include <Eigen/Dense>
#include <string>
#include "Material.h"

class Light{
    public: 
        // Represents some positional/directional property of the light. 
        // typically used when getting Ld. 
        Eigen::Vector3d L; 
        RGB intensity; 
        std::string tag; 
        virtual ~Light();
        // get the direction for this light and point p (from p -> Ld), and s units along li.
        virtual void getLd(const Eigen::Vector3d p, Eigen::Vector3d &Ld, double &s);
        
};

// Flat lighting for an object
class AmbientLight {
    RGB intensity;
    AmbientLight(RGB &i){intensity=i;};
};


class DirectionalLight : public Light{
    DirectionalLight(Eigen::Vector3d &l, RGB &i);
    DirectionalLight(Eigen::Vector3d &l, RGB &i, char &s);
    void getLd(const Eigen::Vector3d p, Eigen::Vector3d &Ld, double &s);

};

// TODO: Implement
class PointLight{

};

#endif
