#include "../../include/Commands/MoveCommand.h"

MoveCommand::MoveCommand(IMovingObject& obj) : _obj(obj)
{

        std::cout << " Constructor Move  Position Point(" << static_cast<double>(_obj.getPosition()._x) << " " << static_cast<double>(_obj.getPosition()._y) << ")\n";
}

void MoveCommand::execute()
{
      
   std::cout<<"MoveCommand secussfully\n";
}
