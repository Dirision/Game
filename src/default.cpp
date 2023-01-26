#include <iostream>
#include <fstream>
#include <Eigen\Dense>
#include <PAM\PAM.h>
// #include <Engine\RTScene.h>
// #include <Engine\Camera.h>
#include <Engine\Base.h>

#include <ctime>




#define PGM_FILE ".\\assets\\HiPgm.pgm"

int defaultPGM(){
    // check if file exists
    // std::ifstream pgmStream(PGM_FILE);
    // if(pgmStream.good()) { std::cout << "PGM Found\n"; }
    //else{
        //PGM not found, build.
    std::cout << "PGM File Missing. Building...\n";
    
    std::cout << "Buidling PGM\n";
    
    const char *d = 
    "0 255 0 0 255 0 255 255 255 255\n"
    "0 230 0 0 230 0 0 255 255 0\n"
    "0 200 0 0 200 0 0 255 255 0\n"
    "0 128 128 128 128 0 0 255 255 0\n"
    "0 92 0 0 92 0 0 255 255 0\n"     
    "0 64 0 0 64 0 0 255 255 0\n"
    "0 32 0 0 32 0 255 255 255 255 0";
    std::string data(d);
        PGM::generateFromString(data,10,7,255);
    return 0;
}

//  Generate a (very basic) ppm
int defaultPPM(){
    std::cout << "Building 3x3 PPM...\n";
    // Eigen::MatrixXf d = Eigen::MatrixXf::Random(9,9);
    std::srand((unsigned int) time(0));
    Eigen::MatrixXd m = Eigen::MatrixXd::Random(3,9);
    m = (m + Eigen::MatrixXd::Constant(3,9,1))*255/2;
    Eigen::Matrix<uint8_t,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> d = m.cast<uint8_t>();    
    PPM::generateFromRaster(3,3,255,d);
    //PPM::generate(3,3,255,d);
    std::cout << "Done!\n";
    return 0;
}


int defaultRT(){
    std::cout << "Generating Sample Raytraced Scene\n";
    
    Camera camera;
    camera.Eye  << 0,1,3;
    camera.u    << 1,0,0;
    camera.v    << 0,1,0;
    camera.w    << 0,0,-1;
    // Think of height/width as how much we are scaling the final image
    camera.width = 1.0;
    camera.height = 1.0;
    camera.fd = 1;
    camera.fov = 90;
    std::vector<std::shared_ptr<Object>> objects;
    Eigen::Vector3d p(0,2,10);
    std::shared_ptr<Material> m(new Material);
    m->rgb = RGB(200,20,20);
    std::shared_ptr<Shape::Sphere> s(new Shape::Sphere(p,2,m));

    Eigen::Vector3d a(6,6,8);
    Eigen::Vector3d b(3,4,7);
    Eigen::Vector3d c(9,4,7);
    std::shared_ptr<Shape::Triangle>  t(new Shape::Triangle(a,b,c));
    
    Eigen::Vector3d o(0,0,0);
    Eigen::Vector3d n(0,1,0);
    std::shared_ptr<Shape::Plane> pl(new Shape::Plane(o,n));

    // objects.insert(1,s);
    objects.push_back(s);
    objects.push_back(t);
    objects.push_back(pl);

    RTScene scene = RTScene(objects,camera,400,680);
    
    uint16_t width,height;
    // const Eigen::Matrix<uint8_t,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> data = scene.GetRaster(width,height);
    // const auto data = scene.GetRaster(width,height);
    
    std::cout << std::numeric_limits<unsigned char>::max();
    scene.Update();
    PPM::generateFromRaster(width,height,255,scene.GetRaster(width,height));
    return 0;
}