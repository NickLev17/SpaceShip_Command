#include <memory>
#include <iostream>
#include "../Interfaces/ICommand.h"
#include "../Interfaces/IMovingObject.h"
class MoveCommand : public ICommand
{
   
   IMovingObject& _obj;

public:
    explicit MoveCommand(IMovingObject& obj);
    

    void execute();
    
};