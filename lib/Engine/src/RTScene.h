/** (Ray Trace Scene) RTScenes will have:
// TODO: IMPLEMENT EACH
// collection of objects                                (IMPLEMENTED)
// a camera                                             (IMPLEMENTED)
// light sources                                        (NOT IMPLEMENTED) 
// Color Models                                         (NOT IMPLEMENTED)
// A raster for output/display(can dump raster to PPM)  (IMPLEMENTED) 
// an update function to update the raster              (IMPLEMENTED)
*/
#ifndef RTSCENE_H
#define RTSCENE_H

#include <stdlib.h>
#include <list>
#include <Eigen/Core>
#include <memory>
#include <vector>

#include "Object.h"
#include "Camera.h"
#include "Ray.h"

class RTScene
{
private:

    // Name of the scene (for management purposes) 
    std::string Name;

    // std::vector<std::shared_ptr<Object>> objects;
    std::vector<std::shared_ptr<Object>> objects;
    Camera camera;

    // raster matrix is just a continous block of memory dedicated to storing 
    // the output pixel data 
    // Eigen storage orders : https://eigen.tuxfamily.org/dox/group__TopicStorageOrders.html
    // the size of the raster is 3*width*height of the scene. W/H need to be 
    // declared at some point, resize functions should be implemented to change
    // the scene's raster matrix size. 
    Eigen::Matrix<uint8_t,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> rasterData;

    // Width/height of our rasterData 
    uint16_t width,height;

    // Aspect Ratio
    double aspectRatio;

    double to,bo,le,ri;
    
    
    
    // Returns first hit & data for ray & objects.
    // False if no intersections
    bool GetFirstHit(Ray &r,const double &minT, double &tValue, int &hO);


public:
    // Have a second constructor that initializes a camera if not provided? 
    //RTScene(std::vector<std::shared_ptr<Object>> &o,Camera &c,const uint16_t h, const uint16_t w);
    RTScene(std::vector<std::shared_ptr<Object>> &o,Camera &c,const uint16_t h, const uint16_t w, std::string name);
    RTScene(std::vector<std::shared_ptr<Object>> &o,Camera &c,const uint16_t h, const uint16_t w): 
        RTScene(o,c,h,w, "NoName!"){};
    RTScene();
    // update Raster matrix basesd on interactions between self camera & objects
    int Update();

   
    const Eigen::Matrix<uint8_t,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> GetRaster(uint16_t  &w,uint16_t &h);
    // Have a function that returns the matrix ? A copy of the matrix? 
    // so that i dont have to bundle ppm ? 
    // You know what ya
    // Did this -> Dump raster to PPM (Should I just return an immutable version of the scene matrix?) 

    // Creates a viewing ray using self camera and its view plane at position (i,j)
    // we provide : 
    // i,j
    // the ray to fill 
    // 
    void GenViewRay(Ray &r, const int i, const int j);

    double getAspectRatio(){
        return aspectRatio;
    }



    // TODO: Add function that returns height/width of our raster data 

    // private function that returns the first hit between 
    // Add a function that adds objects to the object matrix 
    ~RTScene();
};

#endif
