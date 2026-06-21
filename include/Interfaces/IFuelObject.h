#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <math.h>

class IFuelObject
{
public:
    virtual ~IFuelObject() = default;
    virtual double getFuel() const = 0;
    virtual void setFuel(double fuel) = 0;
    virtual void setStepFuel(double step)=0;
    virtual double getStepFuel() const=0;
 
};


