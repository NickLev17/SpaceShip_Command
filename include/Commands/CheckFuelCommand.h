#include <memory>
#include <iostream>
#include "../Interfaces/ICommand.h"
#include "../Interfaces/IFuelObject.h"
class CheckFuelCommand : public ICommand
{
 
 IFuelObject& _obj;
public:
    explicit CheckFuelCommand(IFuelObject& obj);

    void execute();
    
};