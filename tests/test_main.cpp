#include <iostream>
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <math.h>
#include "../include/Interfaces/IMovingObject.h"
#include "../include/Interfaces/IRotatingObject.h"
#include "../include/Interfaces/IFuelObject.h"
#include "../include/Interfaces/IMovingObject.h"
#include "../include/Interfaces/IRotatingObject.h"
// #include "../include/Interfaces/IBurnFuelObject.h"
#include "../include/Commands/MoveCommand.h"
#include "../include/Commands/RotateCommand.h"
#include "../include/Commands/CheckFuelCommand.h"
#include "../include/Commands/BurnFuelCommand.h"
#include "../include/SpaceShip.h"
#include "../include/Commands/MacroCommand.h"
using namespace std;

int main()
{
    std::cout << "Hello, World!" << std::endl;

    // 1. Создаем один объект SpaceShip
    SpaceShip ship_for_commands(20);
    ship_for_commands.setDirection(11);
    ship_for_commands.setAngularVelocity(50);
    ship_for_commands.setDirectionsNumber(360);
    ship_for_commands.setStepFuel(5);
    Point p(15, 24);
    ship_for_commands.setPosition(p);

  

    // vec.push_back(std::make_unique<CheckFuelCommand>(ship_for_commands));
    // vec.push_back(std::make_unique<MoveCommand>(ship_for_commands));
    // vec.push_back(std::make_unique<BurnFuelCommand>(ship_for_commands));
    // vec.push_back(std::make_unique<RotateCommand>(ship_for_commands));

    std::vector<std::unique_ptr<ICommand>> vec;
    vec.push_back(std::make_unique<CheckFuelCommand>(ship_for_commands));
    vec.push_back(std::make_unique<MoveCommand>(ship_for_commands));
    vec.push_back(std::make_unique<BurnFuelCommand>(ship_for_commands));


    std::vector<std::unique_ptr<ICommand>> vec2;
    vec2.push_back(std::make_unique<CheckFuelCommand>(ship_for_commands));
    vec2.push_back(std::make_unique<RotateCommand>(ship_for_commands));
    vec2.push_back(std::make_unique<BurnFuelCommand>(ship_for_commands));

       std::vector<std::unique_ptr<ICommand>> vec3;
    vec3.push_back(std::make_unique<CheckFuelCommand>(ship_for_commands));
    vec3.push_back(std::make_unique<RotateCommand>(ship_for_commands));
    vec3.push_back(std::make_unique<BurnFuelCommand>(ship_for_commands));

     std::vector<std::unique_ptr<ICommand>> vec4;
    vec4.push_back(std::make_unique<CheckFuelCommand>(ship_for_commands));
    vec4.push_back(std::make_unique<RotateCommand>(ship_for_commands));
    vec4.push_back(std::make_unique<BurnFuelCommand>(ship_for_commands));

     std::vector<std::unique_ptr<ICommand>> vec5;
    vec5.push_back(std::make_unique<CheckFuelCommand>(ship_for_commands));
    vec5.push_back(std::make_unique<RotateCommand>(ship_for_commands));
    vec5.push_back(std::make_unique<BurnFuelCommand>(ship_for_commands));

    std::vector<std::unique_ptr<ICommand>> vec_all;
    vec_all.push_back(std::make_unique<MacroCommand>(std::move(vec))); 
    vec_all.push_back(std::make_unique<MacroCommand>(std::move(vec2)));
    vec_all.push_back(std::make_unique<MacroCommand>(std::move(vec3)));
    vec_all.push_back(std::make_unique<MacroCommand>(std::move(vec4)));
    vec_all.push_back(std::make_unique<MacroCommand>(std::move(vec5)));

    MacroCommand macro(std::move(vec_all)); 
 vector<unique_ptr<ICommand>>
    macro.execute();

    return 0;
}

