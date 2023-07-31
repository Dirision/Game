#include "SceneBuilder.h"
#include <nlohmann/json.hpp>

RTScene loadScene(std::string fileName){
    DBGPrint(std::string("LoadScene: "+fileName));
    using json = nlohmann::json;
}