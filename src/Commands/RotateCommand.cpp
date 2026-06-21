#include "../../include/Commands/RotateCommand.h"
RotateCommand::RotateCommand(IRotatingObject& obj) : _obj(obj)
{
        std::cout << " Constructor Rotate"<< _obj.getAngularVelocity()<<"\n";
}


void RotateCommand::execute()
{
    
  
        _obj.setDirection((_obj.getDirection() + _obj.getAngularVelocity()) % _obj.getDirectionsNumber());
       std::cout<<"RotateCommand secussfully. New Direction = "<<_obj.getDirection()<<"\n";
     
}


