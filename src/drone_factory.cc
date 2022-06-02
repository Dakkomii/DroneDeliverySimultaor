#include "drone_factory.h"
#include "json_helper.h"

namespace csci3081 {

DroneFactory::DroneFactory(){}

DroneFactory::~DroneFactory(){}

IEntity* DroneFactory::CreateEntity(const picojson::object& val){

    IEntity* entity_ptr = NULL;

    if(JsonHelper::GetString(val, "type") == "drone"){
        std::vector<float> position = JsonHelper::GetStdFloatVector(val, "position");
        std::vector<float> direction = JsonHelper::GetStdFloatVector(val, "direction");
        entity_ptr = new Drone(position, direction, val);

        return entity_ptr;
    }

    return entity_ptr;
}

}