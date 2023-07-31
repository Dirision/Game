#include "SceneBuilder.h"
#include "EngineDebugFunction.h"
#include <nlohmann/json.hpp>
#include <fstream>
RTScene loadScene(std::string fileName){
    DBGPrint(std::string("LoadScene: "+fileName));
    RTScene rts = RTScene();
    using json = nlohmann::json;
    
    std::ifstream f(fileName);
    json data = json::parse(f);
    return rts;
}