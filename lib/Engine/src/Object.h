#ifndef OBJECT_H
#define OBJECT_H

#include <Eigen/Dense>
#include <memory>
#include "Ray.h"
#include "Material.h"

// All placable items to the scene are objects
class Object{
    protected: 
       
    public:
        std::string Name;

        virtual ~Object();
        std::shared_ptr<Material>       material; 
        // Need to take inspiration from old project function signatures
        // In order to return multiple things
        // We will need back:
        // bool hit  -> if there even was an intersection. Can be the fn return 
        // int t -> depth/how far along the ray we hit
        // Eigen::Vector3d n -> Surface normal calculated at point of intersection
        virtual bool intersect(const Ray &r, double &t, Eigen::Vector3d &n);

        virtual void                    setMaterial(std::shared_ptr<Material> m);
        virtual RGB&                    getMaterialColor();
};

#endif
