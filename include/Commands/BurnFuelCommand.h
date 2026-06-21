#include <memory>
#include <iostream>
#include "../Interfaces/ICommand.h"
#include "../Interfaces/IFuelObject.h"
class BurnFuelCommand : public ICommand
{
IFuelObject& _obj;
public:
        explicit BurnFuelCommand(IFuelObject& obj);

    void execute();
    
};