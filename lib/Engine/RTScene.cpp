// (Ray Trace Scene) RTScenes will have:
// TODO: IMPLEMENT EACH
// collection of objects                    (IMPLEMENTED)
// a camera (can dump raster to PPM)        (IMPLEMENTED)
// light sources                            (NOT IMPLEMENTED) 
// BP Shading                               (NOT IMPLEMENTED)
// A raster for output/display              (PARTIALLY IMPLEMENTED)
// an update function to update the raster  (IMPLEMENTED)
// Materials for objects 

// Eventually
// Texture/Texture Mapping for materials 
// Render Pipeline 




#include <iostream>

#include <stdlib.h>
#include <vector>
#include <memory>
#include <Eigen/Core>

#include "RTScene.h"
#include "Object.h"
#include "Camera.h"
#include "Ray.h"



// 
RTScene::RTScene(std::vector<std::shared_ptr<Object>> &o, Camera &c,const uint16_t h, const uint16_t w)
{
    objects = o;
    camera  = c; 
    height = h;
    width = w;
    aspectRatio = (double)width/(double)height;
    // ri = camera.width;
    // to = camera.height;`
    // le = -ri;
    // bo = -to;
    // // raster matrix is just a continous block of memory dedicated to storing 
    // the output pixel data
    // the size of the raster is 3*width*height of the scene. W/H need to be 
    // declared at some point, resize functions should be implemented to change
    // the scene's raster matrix size. 
    rasterData.resize(height,width*3);
    rasterData.setZero();
}

RTScene::~RTScene()
{
}

int RTScene::Update(){
    
    // s = point in the raster we want to draw (i,j) (S_world = u*camera.u - v*camera.v + w*camera.w)
    // Eigen::Vector3d s;
    // s.w = -camera.d;
    
    // Generate a ray;
    Ray r; r.origin = camera.Eye;
    //Object* hitObj;
    int hitObj = 2;
    //hitObj = objects.front();
    //hitObj = objects.size();
    // will hold distance data;
    double t = 0;
    
    // direction is s - e 
    // for each pixel (i,j) starting at the top left 
    for (int i=0;i < height;i++){
        for (int j=0;j < width;j++){
            // generate a view ray (s) that will be used for our direction for the 
            // raster;
            GenViewRay(r,j,i);
            double minT = camera.fd; 
            // std::cout << r.origin;
            // std::cout << i <<"," <<j << std::endl;
            // std::cout << r.direction << std::endl;
            // std::cout << "Start" << std::endl;
            
            if (GetFirstHit(r,minT,t,hitObj)){                
                // std::cout << i <<"," <<j << std::endl;

                // std::cout << "HIT!\n";
                //std::cout << hitObj << "\n";
                // RGB c = hitObj->getMaterialColor();
                //std::cout << "coloring with index: "  << hitObj << " | \n";
                rasterData(i,j*3  )= objects[hitObj]->material->rgb(0);//hitObj->getMaterialColor()[0];
                // rasterData(i,j*3+1)= hitObj->getMaterialColor()(1);
                // rasterData(i,j*3+2)= hitObj->getMaterialColor()(2);
                rasterData(i,j*3+1)= objects[hitObj]->material->rgb(1);
                rasterData(i,j*3+2)= objects[hitObj]->material->rgb(2);

            }
            else { 
                rasterData(i,j*3)=0x00;
                rasterData(i,j*3+1)=0x00;
                rasterData(i,j*3+2)=0x00;
            }
            // std::cout << "End" << std::endl;
        }
    }
    
    return 0;
}

// Gets the pointer to the array of colors that make up the pixels
// we want to view. 

/*Also returns the dimensions of the raster so that 
* we can format the data.
* const uint8_t* RTScene::GetRasterData(uint16_t  &w,uint16_t &h){
*/

const Eigen::Matrix<uint8_t,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> RTScene::GetRaster(uint16_t  &w,uint16_t &h){
    w = width;
    h = height;
    // return rasterData.data();
    return rasterData;
}


// Returns true if Ray r interesects with any objects stored in the scene 
// tValue is the distance to the point of intersection along R - of the closest hit
// hitObj
bool RTScene::GetFirstHit(Ray &r, const double &minT, double &tValue, int &hO){
    // min t value = camera.d + 1
    double t        = std::numeric_limits<double>::max();

    // val is the distance to the current object we're checking intersections for
    double val;
    bool flag       = false;
    Eigen::Vector3d n; n << 0,0,0;
    // for all objects
    // for (int o = 0; o < static_cast<int>(objects.size());o++){   
//    for (Object *o : objects){
    int size = objects.size();
    for (int i = 0; i < size; i++){
        // Find the closeset intersection of the objects & our viewing ray  
        objects[i]->intersect(r,val,n);
//        if (o->intersect(r,val,n)){
             
        if ((val > minT) && (val < t)){
           
            tValue = val;
            t = val;
            hO = i;
            // std::cout << "closest hit with" << hO << ",obj index is  " << i << ",Compared  || ";   
            flag = true;
        }   
    
    }
    //std::cout << " Returing with index " << hO << " ";
    return flag;
}


void RTScene::GenViewRay(Ray &r, const int j, const int i){
    // std::cout << ri << le << to << bo <<std::endl;
    // std::cout << camera.width << std::endl; 
    // A Big thank you to https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays.html
    // For helping me correct the fov/camera positioning issue
    // double Su =  (camera.width*(j+0.5)/width  - (camera.width/2.0)*aspectRatio);  // le+((ri - le)*(j+0.5))/  camera.width;
    double Su =  (2*((j+0.5)/width)-1)*aspectRatio;
    //double Sv = camera.height*(i+0.5)/height - (camera.height/2.0); //bo+((to - bo)*(i+0.5))/camera.height; // // 
    double Sv =  (2*((i+0.5)/height)-1);
    double Sw = -camera.fd;
    r.direction =  (Su*camera.u - Sv*camera.v  + Sw*camera.w);
    r.direction.normalize();
    //r.direction -= camera.Eye;
    r.origin = camera.Eye;
}



