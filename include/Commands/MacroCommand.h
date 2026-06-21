#include <memory>
#include <iostream>
#include <vector>
#include "../Interfaces/ICommand.h"
class MacroCommand : public ICommand
{
public:

  explicit  MacroCommand(std::vector<std::unique_ptr<ICommand>> commands);
    
    void execute();

private:
   MacroCommand(const MacroCommand&) = delete;
    MacroCommand& operator=(const MacroCommand&) = delete;
    std::vector<std::unique_ptr<ICommand>> _commands;
};

