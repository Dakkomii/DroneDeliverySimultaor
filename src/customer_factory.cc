#include "customer_factory.h"
#include "json_helper.h"

namespace csci3081 {


CustomerFactory::CustomerFactory(){}

CustomerFactory::~CustomerFactory(){}

IEntity* CustomerFactory::CreateEntity(const picojson::object& val){

    IEntity* entity_ptr = NULL;

    if(JsonHelper::GetString(val, "type") == "customer"){
        std::vector<float> position = JsonHelper::GetStdFloatVector(val, "position");
        std::vector<float> direction = JsonHelper::GetStdFloatVector(val, "direction");
        entity_ptr = new Customer(position, direction, val);

        return entity_ptr;
    }

    return entity_ptr;
}

}