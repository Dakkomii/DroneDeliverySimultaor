#include "robot_factory.h"
#include "json_helper.h"

namespace csci3081 {

RobotFactory::RobotFactory(){}

RobotFactory::~RobotFactory(){}

IEntity* RobotFactory::CreateEntity(const picojson::object& val){

    IEntity* entity_ptr = NULL;

    if(JsonHelper::GetString(val, "type") == "robot"){
        std::vector<float> position = JsonHelper::GetStdFloatVector(val, "position");
        std::vector<float> direction = JsonHelper::GetStdFloatVector(val, "direction");
        entity_ptr = new Robot(position, direction, val);

        return entity_ptr;
    }

    return entity_ptr;
}

}