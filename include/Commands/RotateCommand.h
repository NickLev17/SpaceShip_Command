#include <memory>
#include <iostream>
#include "../Interfaces/ICommand.h"
#include "../Interfaces/IRotatingObject.h"
class RotateCommand : public ICommand
{
   IRotatingObject& _obj;

public:
    explicit RotateCommand(IRotatingObject& obj) ;
    

    void execute();
    
};