#include "delivery_logic.h"

namespace csci3081{

DeliveryLogic::DeliveryLogic(){}

DeliveryLogic::~DeliveryLogic(){}

void DeliveryLogic::setUp(std::vector<IEntity*> entities, std::vector<IEntityObserver*> observers, const IGraph* graph){
    this->entities_ = entities;
    this->observers = observers;
    this->graphs = graph;
}

void DeliveryLogic::SendNotification(std::string value,  IEntity* entity, std::vector<std::vector<float>> path){
        picojson::object obj = JsonHelper::CreateJsonNotification();
	    JsonHelper::AddStringToJsonObject(obj, "value", value);  //or AddValuetoJsonObject

	    if ((dynamic_cast<Drone*>(entity)) && (value == "moving")){
		    Drone* drone = dynamic_cast<Drone*>(entity);
		    JsonHelper::AddStdVectorVectorFloatToJsonObject(obj,"path",path);
	    }
	    if ((dynamic_cast<Robot*>(entity)) && (value == "moving")){
		    Robot* robot = dynamic_cast<Robot*>(entity);
		    JsonHelper::AddStdVectorVectorFloatToJsonObject(obj,"path",path);
	    }
	    const IEntity* entity_ = entity;
	    for(IEntityObserver* observer : observers){
		    if(observer != NULL){
			    observer->OnEvent((JsonHelper::ConvertPicojsonObjectToValue(obj)), *entity_);
		    }
	}
}

void DeliveryLogic::schedule(IEntity* package, IEntity* customer){
    //search trhough entity list and find a drone that is free.
    //use graph and call getPath twice, store them inside drone class
    //have a bool method to true or false is is making a delivery
    std::vector<std::vector<float>> path {{0,0,0}};
	Package* pack = dynamic_cast<Package*>(package);
	Customer* cust = dynamic_cast<Customer*>(customer);

	pack->SetCustomer(cust);
	packages.push_back(pack);

	for (int i = 0; i < entities_.size(); i++){
		IEntity* temp = entities_.at(i);
		Drone* d = dynamic_cast<Drone*>(temp);

		if(d){
			if(!d->IsDelivering() && !d->isBaterryDepleted()){
				picojson::object obj = d->GetDetails();
				std::string typePath;
				if(JsonHelper::ContainsKey(obj, "path")){
    				typePath = JsonHelper::GetString(obj, "path");
  				}
  				else{
    				JsonHelper::AddStringToJsonObject(obj, "path", "smart");
    				typePath = JsonHelper::GetString(obj, "path");
  				}

				if(typePath == "smart"){
					strategy = new ConcreteSmart();
					ConcreteSmart* smart = dynamic_cast<ConcreteSmart*>(strategy);
					smart->SetGraph(graphs);
					smart->SetUp(d->GetPosition(), pack->GetPosition(), cust->GetPosition());
					d->SetStrategy(smart);
					d->SetPackage(pack);
					d->SetRouteOne();
					d->SetRouteTwo();
					SendNotification("scheduled",package,path);  //package scheduled notification
					d->SetDelivering(true);
					packages.erase(std::remove(packages.begin(), packages.end(), pack), packages.end());
					return;
				}
				else if(typePath == "beeline"){
					strategy = new ConcreteBeeline();
					ConcreteBeeline* beeline = dynamic_cast<ConcreteBeeline*>(strategy);
					beeline->SetUp(d->GetPosition(), pack->GetPosition(), cust->GetPosition());
					d->SetStrategy(beeline);
					d->SetPackage(pack);
					d->SetRouteOne();
					d->SetRouteTwo();
					SendNotification("scheduled",package,path);  //package scheduled notification
					d->SetDelivering(true);
					packages.erase(std::remove(packages.begin(), packages.end(), pack), packages.end());
					return;
				}
				else if(typePath == "parabolic"){
					strategy = new ConcreteParabolic();
					ConcreteParabolic* parabolic = dynamic_cast<ConcreteParabolic*>(strategy);
					parabolic->SetUp(d->GetPosition(), pack->GetPosition(), cust->GetPosition());
					d->SetStrategy(parabolic);
					d->SetPackage(pack);
					d->SetRouteOne();
					d->SetRouteTwo();
					SendNotification("scheduled",package,path);  //package scheduled notification
					d->SetDelivering(true);
					packages.erase(std::remove(packages.begin(), packages.end(), pack), packages.end());
					return;
				}
			}
		}
		else if(d == NULL){
			Robot* r = dynamic_cast<Robot*>(temp);
			if(r){
				if(!r->IsDelivering() && !r->isBaterryDepleted()){
					picojson::object obj = r->GetDetails();
					std::string typePath;
					if(JsonHelper::ContainsKey(obj, "path")){
    					typePath = JsonHelper::GetString(obj, "path");
  						}
  					else{
    					JsonHelper::AddStringToJsonObject(obj, "path", "smart");
    					typePath = JsonHelper::GetString(obj, "path");
  					}

					if(typePath == "smart"){
						strategy = new ConcreteSmart();
						ConcreteSmart* smart = dynamic_cast<ConcreteSmart*>(strategy);
						smart->SetGraph(graphs);
						smart->SetUp(r->GetPosition(), pack->GetPosition(), cust->GetPosition());
						r->SetStrategy(smart);
						r->SetPackage(pack);
						r->SetRouteOne();
						r->SetRouteTwo();
						SendNotification("scheduled",package,path);  //package scheduled notification
						r->SetDelivering(true);
						packages.erase(std::remove(packages.begin(), packages.end(), pack), packages.end());
						return;
					}
				}
			}
		}
		else{
			return;
		}

	}
}

void DeliveryLogic::move(float dt){
    float time = dt;
	std::vector<std::vector<float>> path {{0,0,0}};

	for (int i = 0; i < entities_.size(); i++){
		IEntity* temp = entities_.at(i);
		Drone* tempDrone = dynamic_cast<Drone*>(temp);
		if(tempDrone){
			if(tempDrone->IsDelivering() && !tempDrone->isBaterryDepleted()){

				tempDrone->update(time);

				if(tempDrone->isBaterryDepleted()){
					Package* ptemp = tempDrone->GetPackageObject();
					packages.push_back(ptemp);
					SendNotification("idle",tempDrone, path);
					//tempDrone->SetDelivering(false);

					tempDrone->decorate();
					EntityBase* redDrone = new RedEntity(tempDrone);
					redDrone->decorate();

					picojson::object details = redDrone->GetDetails();

				//	JsonHelper::AddStringToJsonObject(details, "color" , "0xFF0000"); //this one
					 //details["color"] = picojson::value("0xFF0000"); //or this one
					 picojson::object obj;
					// //SendNotification("updateDetails", tempDrone, path);
					JsonHelper::AddStringToJsonObject(obj, "type", "notify");
					JsonHelper::AddStringToJsonObject(obj, "value", "updateDetails");  //or AddValuetoJsonObject
					JsonHelper::PrintEntityDetails(obj);
					obj["details"] = picojson::value(details);


					for(IEntityObserver* observer : observers){
						if(observer != NULL){
					observer->OnEvent((JsonHelper::ConvertPicojsonObjectToValue(obj)), *tempDrone);
						}
					}
					//break;
				}
				else{  //battery is not dead
					tempDrone->decorate();
					EntityBase* greenDrone = new GreenEntity(tempDrone);
					greenDrone->decorate();

					picojson::object details = greenDrone->GetDetails();

				//	JsonHelper::AddStringToJsonObject(details, "color" , "0xFF0000"); //this one
					 //details["color"] = picojson::value("0xFF0000"); //or this one
					 picojson::object obj;
					// //SendNotification("updateDetails", tempDrone, path);
					JsonHelper::AddStringToJsonObject(obj, "type", "notify");
					JsonHelper::AddStringToJsonObject(obj, "value", "updateDetails");  //or AddValuetoJsonObject
					JsonHelper::PrintEntityDetails(obj);
					obj["details"] = picojson::value(details);


					for(IEntityObserver* observer : observers){
						if(observer != NULL){
					observer->OnEvent((JsonHelper::ConvertPicojsonObjectToValue(obj)), *tempDrone);
						}
					}

				} //end of else

				// add changes here
				if (!tempDrone->GetPackage() && !tempDrone->GetDroneToPackage()){
					SendNotification("moving",tempDrone, tempDrone->GetRouteOne()); //drone/package to customer
					tempDrone->SetDroneToPackage(true); //drone to package
				}

				// add changes here
				if (tempDrone->GetPackage() == true && !tempDrone->GetDroneHasPackage()){
					SendNotification("en route",tempDrone->GetPackageObject(), path);  //package picked up notification
					SendNotification("moving",tempDrone, tempDrone->GetRouteTwo()); //drone/package to customer
					tempDrone->SetDroneHasPackage(true);
					tempDrone->SetDroneToCustomer(false);
				}

				if (tempDrone->IsDelivering() == false){
					SendNotification("delivered",tempDrone->GetPackageObject(),path);  //package picked up notification
				}

			}
			else if (!tempDrone->IsDelivering()){
				for(int k = 0 ; k < packages.size();k++){
					if(!packages[k]->GetIsDelivered()){
						// add changes here
						Package* ptemp = packages.at(k);
						Customer* ctemp = packages.at(k)->GetCustomer();
						packages.erase(std::remove(packages.begin(), packages.end(), packages.at(k)), packages.end());
						tempDrone->Reset();
						schedule(ptemp,ctemp);
						return;
					}
					else{
						packages.erase(std::remove(packages.begin(), packages.end(), packages.at(k)), packages.end());
					}
				} //end of for packages

				if(!tempDrone->GetDronefinished()){
					SendNotification("idle",tempDrone, path);
					tempDrone->SetDronefinished(true);
				}

			}
		}
		else if(tempDrone == NULL){
		Robot* tempRobot = dynamic_cast<Robot*>(temp);
		if(tempRobot){
			if(tempRobot->IsDelivering()&& !tempRobot->isBaterryDepleted()){

				tempRobot->update(time);

				if(tempRobot->isBaterryDepleted()){
					Package* ptemp = tempRobot->GetPackageObject();
					packages.push_back(ptemp);
					SendNotification("idle",tempRobot, path);

					tempRobot->decorate();
					EntityBase* redRobot = new RedEntity(tempRobot);
					redRobot->decorate();

					picojson::object details = redRobot->GetDetails();

				//	JsonHelper::AddStringToJsonObject(details, "color" , "0xFF0000"); //this one
					 //details["color"] = picojson::value("0xFF0000"); //or this one
					 picojson::object obj;
					// //SendNotification("updateDetails", tempDrone, path);
					JsonHelper::AddStringToJsonObject(obj, "type", "notify");
					JsonHelper::AddStringToJsonObject(obj, "value", "updateDetails");  //or AddValuetoJsonObject
					JsonHelper::PrintEntityDetails(obj);
					obj["details"] = picojson::value(details);


					for(IEntityObserver* observer : observers){
						if(observer != NULL){
					observer->OnEvent((JsonHelper::ConvertPicojsonObjectToValue(obj)), *tempRobot);
						}
					}
					return;
				}
				else{  //battery is not dead
					tempRobot->decorate();
					EntityBase* greenRobot = new GreenEntity(tempRobot);
					greenRobot->decorate();

					picojson::object details = greenRobot->GetDetails();

				//	JsonHelper::AddStringToJsonObject(details, "color" , "0xFF0000"); //this one
					 //details["color"] = picojson::value("0xFF0000"); //or this one
					 picojson::object obj;
					// //SendNotification("updateDetails", tempDrone, path);
					JsonHelper::AddStringToJsonObject(obj, "type", "notify");
					JsonHelper::AddStringToJsonObject(obj, "value", "updateDetails");  //or AddValuetoJsonObject
					JsonHelper::PrintEntityDetails(obj);
					obj["details"] = picojson::value(details);


					for(IEntityObserver* observer : observers){
						if(observer != NULL){
					observer->OnEvent((JsonHelper::ConvertPicojsonObjectToValue(obj)), *tempRobot);
						}
					}

				} //end of else

				if (!tempRobot->GetPackage() && !tempRobot->GetRobotToPackage()){
					SendNotification("moving",tempRobot, tempRobot->GetRouteOne()); //robot/package to customer
					tempRobot->SetRobotToPackage(true); //robot to package
				}
				 if (tempRobot->GetPackage() == true && !tempRobot->GetRobotHasPackage()){
				 	SendNotification("en route",tempRobot->GetPackageObject(), path);  //package picked up notification
					SendNotification("moving",tempRobot, tempRobot->GetRouteTwo()); //drone/package to customer
					tempRobot->SetRobotHasPackage(true);
					tempRobot->SetRobotToCustomer(true);
				 }

				 if (tempRobot->IsDelivering() == false){
				 	SendNotification("delivered",tempRobot->GetPackageObject(),path);  //package picked up notification
				 }

			}
			else if (!tempRobot->IsDelivering()){
				for(int k = 0 ; k < packages.size();k++){
					if(!packages[k]->GetIsDelivered()){
						Package* ptemp = packages.at(k);
						Customer* ctemp = packages.at(k)->GetCustomer();
						packages.erase(std::remove(packages.begin(), packages.end(), packages.at(k)), packages.end());
						tempRobot->Reset();
						schedule(ptemp,ctemp);
						return;
					}
					else{
						packages.erase(std::remove(packages.begin(), packages.end(), packages.at(k)), packages.end());
						}
				}
				if(!tempRobot->GetRobotfinished()){
					SendNotification("idle",tempRobot, path);
					tempRobot->SetRobotfinished(true);
				}
			}
		}
	}

	}
}
}
