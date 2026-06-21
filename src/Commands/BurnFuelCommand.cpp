#include "../../include/Commands/BurnFuelCommand.h"

BurnFuelCommand::BurnFuelCommand(IFuelObject& obj) : _obj(obj)
{

       std::cout << " Constructor BurnFuelCommand\n";
}

void BurnFuelCommand::execute()
{
    
       
     auto fuel=_obj.getFuel();
     _obj.setFuel(fuel-(_obj.getStepFuel()));

         std::cout<<"BurnFuelCommand "<<" wos fuel "<<fuel<<" step fuel "<<_obj.getStepFuel()<<" Total "<<_obj.getFuel()<<"\n";
       
        
}
