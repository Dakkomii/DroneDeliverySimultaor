#include "composite_factory.h"
#include "json_helper.h"
#include "drone_factory.h"

namespace csci3081 {



CompositeFactory::CompositeFactory(){}

CompositeFactory::~CompositeFactory(){

    for (int i = 0; i < factories.size(); i++)
    {
        delete factories.at(i);
    }
    factories.clear();
}

void CompositeFactory::AddFactory(entity_project::IEntityFactory* factory){

    factories.push_back(factory);
}


IEntity* CompositeFactory::CreateEntity(const picojson::object& val){ 


    for (int i = 0; i < factories.size() ; i++){
        IEntity* entity = factories.at(i)->CreateEntity(val);
        if(entity){
            return entity;
        }
    }
    return NULL;
}  

std::vector<IEntityFactory*> CompositeFactory::GetFactories(){
    return factories;
}
}