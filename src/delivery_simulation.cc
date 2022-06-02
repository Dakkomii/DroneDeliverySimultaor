#include "delivery_simulation.h"
#include "entity_base.h"
#include "json_helper.h"
#include "composite_factory.h"


namespace csci3081 {

DeliverySimulation::DeliverySimulation() {
	Composite_factory = new CompositeFactory();
	Composite_factory->AddFactory(new DroneFactory());
	Composite_factory->AddFactory(new RobotFactory());
	Composite_factory->AddFactory(new PackageFactory());
	Composite_factory->AddFactory(new CustomerFactory());

	packid = 20;
	custid = 50;
	entityId = 1;
	dronefinished = false;
	robotfinished = false;

	strategy = NULL;

	logic = new DeliveryLogic();//logic will hold and have access to the methos that will run most of simulation
}

DeliverySimulation::~DeliverySimulation() {
	delete strategy;
}

IEntity* DeliverySimulation::CreateEntity(const picojson::object& val) {
	IEntity* entity = Composite_factory->CreateEntity(val);
	if(entity){
		EntityBase* base = dynamic_cast<EntityBase*>(entity);
		base->SetId(entityId++);
	}
	return entity;


}


void DeliverySimulation::AddFactory(IEntityFactory* factory) {
	comp.push_back(factory);
}

void DeliverySimulation::AddEntity(IEntity* entity) {
	this->entities_.push_back(entity);
}

void DeliverySimulation::SetGraph(const IGraph* graph) {
	graphs = graph;
}

void DeliverySimulation::ScheduleDelivery(IEntity* package, IEntity* dest) {

	logic->setUp(entities_, observers, graphs);
	logic->schedule(package,dest);

}

void DeliverySimulation::AddObserver(IEntityObserver* observer) {
	observers.push_back(observer);
}

void DeliverySimulation::RemoveObserver(IEntityObserver* observer) {
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

const std::vector<IEntity*>& DeliverySimulation::GetEntities() const { return entities_; }


void DeliverySimulation::Update(float dt) {
	logic->move(dt);
}


// DO NOT MODIFY THE FOLLOWING UNLESS YOU REALLY KNOW WHAT YOU ARE DOING
void DeliverySimulation::RunScript(const picojson::array& script, IEntitySystem* system) const {
  JsonHelper::PrintArray(script);
  IDeliverySystem* deliverySystem = dynamic_cast<IDeliverySystem*>(system);
	if (deliverySystem) {

	    // To store the unadded entities_
	    std::vector<IEntity*> created_entities;

		for (unsigned int i=0; i < script.size(); i++) {
			const picojson::object& object = script[i].get<picojson::object>();
			const std::string cmd = object.find("command")->second.get<std::string>();
			const picojson::object& params = object.find("params")->second.get<picojson::object>();
			// May want to replace the next few if-statements with an enum
			if (cmd == "createEntity") {
				IEntity* entity = NULL;
				entity = deliverySystem->CreateEntity(params);
				if (entity) {
					created_entities.push_back(entity);
				} else {
					std::cout << "Null entity" << std::endl;
				}
			}
			else if (cmd == "addEntity") {
				int ent_index = static_cast<int>(params.find("index")->second.get<double>());
				if (ent_index >= 0 && ent_index < created_entities.size()) {
					deliverySystem->AddEntity(created_entities[ent_index]);
				}
			}
			else if (cmd == "scheduleDelivery" ) {
				int pkg_index = static_cast<int>(params.find("pkg_index")->second.get<double>());
				int dest_index = static_cast<int>(params.find("dest_index")->second.get<double>());
				if (pkg_index >= 0 && pkg_index < system->GetEntities().size()) {
					IEntity* pkg = deliverySystem->GetEntities()[pkg_index];
					if (dest_index >= 0 && pkg_index < system->GetEntities().size()) {
						IEntity* cst = system->GetEntities()[dest_index];
						if (pkg && cst) {
							deliverySystem->ScheduleDelivery(pkg, cst);
						}
					}
				}
				else {
					std::cout << "Failed to schedule delivery: invalid indexes" << std::endl;
				}
			}
		}
	}
}

}
