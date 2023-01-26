#ifndef SHAPE_H
#define SHAPE_H

#include <Eigen/Dense>
#include "Object.h"
#include "Ray.h"


namespace Shape{
    class Sphere : public Object{
        protected:
            RGB& getMaterialColor();
        public: 
            Eigen::Vector3d         center;
            double                  radius;
            // c = Center position, r = radius
                                      Sphere(Eigen::Vector3d &c,double r);
                                      Sphere(Eigen::Vector3d &c,double r,std::shared_ptr<Material> &m);
            bool                      intersect(const Ray &r, double &t, Eigen::Vector3d &n);
            void                      setMaterial(std::shared_ptr<Material> m);
            
    };
    
    class Triangle : public Object{
        protected:      
            RGB& getMaterialColor();
            Eigen::Vector3d a;
            Eigen::Vector3d b;
            Eigen::Vector3d c; 
        public: 
            Triangle(Eigen::Vector3d A,Eigen::Vector3d B,Eigen::Vector3d C);
            bool                     intersect(const Ray &r, double &t, Eigen::Vector3d &n);
            void                     setMaterial(std::shared_ptr<Material> m);
          
    };
    
    // Planes are polygons that have no verticies. Potentially use this as a base
    // class for n sided polygons later?
    class Plane : public Object{    
        protected:
            RGB& getMaterialColor();
            Eigen::Vector3d p; 
            Eigen::Vector3d n;
        public:
            // Create new plane object with normal N with point P being a point on the plane
            Plane(Eigen::Vector3d P, Eigen::Vector3d N);
            Plane(Eigen::Vector3d P, Eigen::Vector3d N,std::shared_ptr<Material> m);
            bool                     intersect(const Ray &r, double &t, Eigen::Vector3d &N);
            void                     setMaterial(std::shared_ptr<Material> m);

    };
}

#endif