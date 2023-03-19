#include <Eigen/Dense>
#include "Object.h"
#include "Ray.h"
#include "Shape.h"
#include "Material.h"

#include <iostream>



Shape::Sphere::Sphere(Eigen::Vector3d &c,double r){
    center = c; 
    radius = r;
    std::shared_ptr<Material> m(new Material());
    material = m;
    material->rgb = RGB(255,255,255);
}

Shape::Sphere::Sphere(Eigen::Vector3d &c,double r,std::shared_ptr<Material> &m){
    center = c; 
    radius = r;
    material = m;
}

bool Shape::Sphere::intersect(const Ray &r, double &  t, Eigen::Vector3d &n){
    Eigen::Vector3d ec  = r.origin - center;
    double bottom       = r.direction.dot(r.direction);
    double B            = r.direction.dot(ec);
    double c            = ec.dot(ec)-radius*radius;
    double discrim      = (B*B)-(bottom*c);
    if (discrim < 0) return false;
    if (discrim == 0){
        t               = -B/bottom;
        n               = 2*(ec + t*r.direction);
        return true; 
    } else { 
        double tA       = std::abs((-B - sqrt(discrim))/bottom);
        double tB       = (-B + sqrt(discrim))/bottom;
        tA <= tB ? t = tA : t = tB;
        n = 2*(ec + t*r.direction);
        return true; 
    }
    // This should never be reached! 
    return false;
};
 
void Shape::Sphere::setMaterial(std::shared_ptr<Material> m){
    material = m;
}
RGB& Shape::Sphere::getMaterialColor(){
    return material->rgb;
}

////////////////////////////////////////////////////////////////////////////////
// Triangle

Shape::Triangle::Triangle(Eigen::Vector3d A,Eigen::Vector3d B,Eigen::Vector3d C){
    a = A;
    b = B;
    c = C;
    std::shared_ptr<Material> m(new Material);
    m->rgb = RGB(50,50,255);
    material = m;
}
bool Shape::Triangle::intersect(const Ray &r, double &t, Eigen::Vector3d &n){
    Eigen::Vector3d ab = a-b;
    Eigen::Vector3d ac = a-c;
    Eigen::Vector3d ae = a-r.origin;
    Eigen::Matrix3d A; 
    A << ab,ac,r.direction;
    double a = A.determinant();
    Eigen::Matrix3d Y; 
    Y << ab,ae,r.direction;
    double y = Y.determinant()/a;
    if ((y < 0) || (y >  1)) return false;
    Eigen::Matrix3d B;
    B << ae,ac,r.direction;
    double b = B.determinant()/a;
    if (b < 0 || b > 1-y) return false;
    Eigen::Matrix3d T;
    T << ab,ac,ae;
    t = T.determinant()/a;
    // std::cout << "HIT!!!\n";
    return true;
};
void Shape::Triangle::setMaterial(std::shared_ptr<Material> m){  
    //material = m;
};
RGB& Shape::Triangle::getMaterialColor(){
    return material->rgb;
};


Shape::Plane::Plane(Eigen::Vector3d P, Eigen::Vector3d N){
    p = P;
    n = N;
    std::shared_ptr<Material> m(new Material);
    m->rgb = RGB(50,255,50);
    material = m;
};
Shape::Plane::Plane(Eigen::Vector3d P, Eigen::Vector3d N,std::shared_ptr<Material> m){
    p = P;
    n = N;
    material = m;
};
bool Shape::Plane::intersect(const Ray &r, double &t, Eigen::Vector3d &N){
    double d = r.direction.dot(n);
    // std::cout << "d: "<< d << " ";
    if (d == 0){return false;}
    double T = (p - r.origin).dot(n)/d;
    if (T < 0){return false;}
    N = n; 
    t = T;
    // std::cout << t << std::endl;
    return true;
};
void Shape::Plane::setMaterial(std::shared_ptr<Material> m){
    material = m;  
};

RGB& Shape::Plane::getMaterialColor(){
    return material->rgb;
};
