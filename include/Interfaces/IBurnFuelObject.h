#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <math.h>

class IBurnFuelObject
{
public:
    virtual ~IBurnFuelObject() = default;
    virtual double getFuel() const = 0;
    virtual void setFuel(double fuel) = 0;
 
};


