#include <iostream>

#include "default.h"
#include "EngineDebugFunction.h"

/**
 * TODO:
 * - Fix help section
 * - Check Engine/RTScene.h for more TODO
 * 
 * 
 * -FUTURE TODO:
 * - OGL Integration
 * - Implement rendering to win32 window: https://www.youtube.com/watch?v=vEFpaJdKcYU (only
 *      if going for an old look/learning experience)
 * - 
 * 
*/


int main(int argc, char **argv){
    using namespace std;
    DBGPrint(std::string("DEBUGGING IS ENABLED!"));
    // defaultRT();
    // argc=5;
    if (argc == 1){
        cout << "USAGE: .\\myRT <mode> [options] \n";
        cout << "MODES:\n1: Raster PGM [PathOfPgmtoProcess]\n";
        // TODO: FINISH HELP
        cout << "If PGM/JSON not provided, one will be generated and used\n";
        cout << "Will convert image to pbm (Black and White Pixels) based on Y\n";
        cout << "2: Raster PPM\nWill generate random PPM\n";
        cout << "3: Raster Shapes [SceneJason] - Will output a raster of a raytraced scene, specified\n\tby [Scene.json]\n";
        cout << "4: Run SampleGame";
        cout << "Draws shapes following a schema\n";
        cout << "Will draw 3 basic shapes if JSON not provided\n";
    }
    // handle the cases where the user doesnt provide a file to read from
    else if (argc >= 2){
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
            cout << "RayTraced Scene\n";
            if (argc == 3){
                defaultRTFromFile(argv[2]);
            } else {
                defaultRT();
            }
            break;
        default:
            cout << "Unknown";
            break;
        }
    }
    

    std::cout << "Finished\n";
    return 0;
    
}

/*
Should this be in the engine lib? Then where does all the functionality happen in the actual game?
Do I treat the game repo itself like a thin entry point like a python module (doEverything() function)
What should happen when we launch the app

What if this game just refers to the orginization as part of the game rpo? 
EngineGame constructor does all the setup, then there are controls inside this 

========================
Game should be a sample game. Should exist in the game project. Anything we use should come from 
the library, and game main can be where we enter the sample game. 



1. $> Game.exe samepleJson
2. Enter main
3. Enter GameMain after parsing args 
Are games objects? And we store the scene + anything meta in the object? 
Game objects will need to track the active scene as well 
I.e> Store all scenes (make a list/ptr to all active scenes?) Will game objects 
handle transitions between scenes (maybe make a callback/function in game that scenes can call to
request another scene to load (i.e. attempt to load RTScene named menu, crash on failure, swap 
active scene in the rendering window))
3.1. What do we pass to game main? Or should game main handle the loading? 
Should loading the same scene be done in the default class as an option? Perhaps it should for atleast
this one scene? We are just loading the one scene / stl after all ? then we add an option 4 (argv)
for testing the actual game!
Why not pass argc and argv to GameMain? Could start loading the scene from in there? 
Maybe add a second constructor for passing in the scene you want to load? 




3.2 GameMain begins by loading everything necessary 
4. Enter GameMainloop


game.h should have access to graphics/hw layer libraries. 


*/

// Game main entry point 
void GameMain(){};

