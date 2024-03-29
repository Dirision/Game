#include "Object.h"
#include "Material.h"

Object::~Object(){};
bool Object::intersect(const Ray &r, double &t, Eigen::Vector3d &n){return false;};
void Object::setMaterial(std::shared_ptr<Material> m){return;};
RGB& Object::getMaterialColor()     {return material->rgb;};