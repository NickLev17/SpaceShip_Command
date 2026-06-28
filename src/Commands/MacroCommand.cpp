#include "iostream"
#include "../../include/Commands/MacroCommand.h"

 
    MacroCommand::MacroCommand(std::vector<std::unique_ptr<ICommand>> commands) : _commands(std::move(commands))
     {
std::cout<<"Constructor MacroCommand: size commands "<<_commands.size()<<"\n";
     }
    
    void MacroCommand::execute() {

           std::cout<<"Macrocommand : { \n";
        for(int i=0; i<static_cast<int>(_commands.size()); i++) {
      try
      { 
        _commands.at(i).get()->execute(); 
        
      }
      catch(const char* exceptionMessage) { 
                       std::cerr << "Error in command: " << exceptionMessage << std::endl;
       
             break; 
        }
            
        }
              std::cout<<" } \n";
    }


    

  
