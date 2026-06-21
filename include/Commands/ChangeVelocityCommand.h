#include <memory>
#include <iostream>
#include "../Interfaces/ICommand.h"
#include "../Interfaces/IRotatingObject.h"
#include "../Interfaces/IMovingObject.h"
class ChangeVelocityCommand : public ICommand
{
  
 IMovingObject& _mov_obj;
 IRotatingObject& _rot_obj;

public:
  
    explicit ChangeVelocityCommand(IMovingObject& mov_obj,IRotatingObject& rot_obj);

    void execute();
    
};