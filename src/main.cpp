#include <iostream>
#include "default.h"

/**
 * PBM : Black and white via 0 - 1
 * PGM : Greyscale image, intensity is specified as 0 <= Limit <= 65536
 * PPM : RGB image. values are represented as tuples of 3 | r,g,b <= 255
 */


/**
 * TODO:
 * - Fix help section
 * - Finish section 3 
 * - Implement Scene 
 * - Implement Shapes
 * - Implement outputting to ppm 
 * 
 * -FUTURE TODO:
 * - Implement rendering to win32 window: https://www.youtube.com/watch?v=vEFpaJdKcYU
 * - 
 * 
*/


int main(int argc, char **argv){
    using namespace std;
    defaultRT();
    argc=5;
    if (argc == 1){
        cout << "USAGE: .\\myRT <mode> [options] \n";
        cout << "MODES:\n1: Raster PGM [PathOfPgmtoProcess]\n";
        // TODO: FINISH HELP
        cout << "If PGM/JSON not provided, one will be generated and used\n";
        cout << "Will convert image to pbm (Black and White Pixels) based on Y\n";
        cout << "2: Raster PPM\nWill generate random PPM\n";
        cout << "3: Raster Shapes [ShapeDataJason]\n";
        cout << "Draws shapes following a schema\n";
        cout << "Will draw 3 basic shapes if JSON not provided\n";
    }
    // handle the cases where the user doesnt provide a file to read from
    else if (argc == 2){
        cout<< *argv[1] << endl;
        switch (int(*argv[1])-48)
        {
        case 1:
            cout << "PGM - NO FILE\n";
            defaultPGM();
            break;
        case 2: 
            cout << "PPM - NO FILE\n";
            defaultPPM();
            break;
        case 3:
            cout << "RayTraced Scene - NO DATA\n";
            defaultRT();
            break;
        default:
            cout << "Unknown";
            break;
        }
    }
    

    std::cout << "Finished\n";
    return 0;
}