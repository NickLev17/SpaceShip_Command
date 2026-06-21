#include "../include/SpaceShip.h"

SpaceShip::SpaceShip(double fuel) : fuelLevel(fuel)
{
    std::cout << "Constructor SpaceShip\n";
    
}
void SpaceShip::setFuel(double amount)
{
    fuelLevel = amount;

}


double SpaceShip::getFuel() const
{
    return fuelLevel;
}
double SpaceShip::getStepFuel() const
{
    return _stepFuel;
}
void SpaceShip::setStepFuel(double step) 
{
    _stepFuel=step;
}
Point SpaceShip::getPosition() const
{
    return _position;
}
void SpaceShip::setPosition(Point newPos)
{
    
    _position=newPos;
   
}
vector<Point>& SpaceShip::getVelocity()
{
    return _velocity;
}

int SpaceShip::getDirection() const
{
    return _direction;
}
void SpaceShip::setDirection(int newV)
{
    _direction=newV;
}
int SpaceShip::getAngularVelocity() const
{
    return _angularVelocity;
}

int SpaceShip::getDirectionsNumber() const
{
    return _directionNumber;
}

void SpaceShip::setAngularVelocity(int newV)
{
    _angularVelocity=newV;
}

void SpaceShip::setDirectionsNumber(int newV)
{
_directionNumber=newV;
}