#include <Eigen/Dense>
#include <string>
#include "Material.h"

#include "Light.h"

Light::~Light(){};
void Light::getLd(const Eigen::Vector3d p, Eigen::Vector3d &Ld, double &s){};


DirectionalLight::DirectionalLight(Eigen::Vector3d &l, RGB &i){
    L = l;
    intensity = i; 
    Tag = "";
}
DirectionalLight::DirectionalLight(Eigen::Vector3d &l, RGB &i, char &tag){
    L = l;
    intensity = i; 
    Tag = tag;
}
void DirectionalLight::getLd(const Eigen::Vector3d p, Eigen::Vector3d &Ld, double &s){
    // recall: L is from our lightsource into the scene, therefore, ld will be the negative of L
    //         as we are going from point to light
    Ld = -L.normalized();
    // intersection point does not matter for this light
    s = std::numeric_limits<double>::max();
}

PointLight::PointLight(Eigen::Vector3d &l, RGB &i){
    L = l;
    intensity = i;
}
PointLight::PointLight(Eigen::Vector3d &l, RGB &i, char &s){

}

// Recall that p Must be a point in world space
void PointLight::getLd(const Eigen::Vector3d p, Eigen::Vector3d &Ld, double &s){
    Ld = (p - L).normalized();
};
