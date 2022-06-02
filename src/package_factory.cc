#include "package_factory.h"
#include "json_helper.h"

namespace csci3081 {


PackageFactory::PackageFactory(){}

PackageFactory::~PackageFactory(){}

IEntity* PackageFactory::CreateEntity(const picojson::object& val){

    IEntity* entity_ptr = NULL;

    if(JsonHelper::GetString(val, "type") == "package"){
        std::vector<float> position = JsonHelper::GetStdFloatVector(val, "position");
        std::vector<float> direction = JsonHelper::GetStdFloatVector(val, "direction");
        entity_ptr = new Package(position, direction, val);

        return entity_ptr;
    }

    return entity_ptr;
}

}