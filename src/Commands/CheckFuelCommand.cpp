#include "../../include/Commands/CheckFuelCommand.h"

CheckFuelCommand::CheckFuelCommand(IFuelObject& obj) : _obj(obj)
{

       // std::cout << " Constructor CheckFuelCommand " <<obj.get()->getFuel();
       std::cout << " Constructor CheckFuelCommand getFuel="<<_obj.getFuel()<<"\n";
}

void CheckFuelCommand::execute()
{
         
        if(_obj.getFuel()<_obj.getStepFuel()) //проверяю что осталось больше топлива чем потребуется затратить на один шаг
        {
                throw "Not Fuel";
       }
       else
        {
std::cout<<"Check faul Successfully. Total fuel="<<_obj.getFuel()<<"\n";
        }
     
        
}
