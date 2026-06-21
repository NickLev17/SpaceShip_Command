#pragma once
class IRotatingObject
{
public:
  virtual ~IRotatingObject() = default;

  // направление
  virtual int getDirection() const = 0;
  virtual void setDirection(int newV) = 0;

  //  углолвая скорость
  virtual int getAngularVelocity() const = 0;
  virtual void setAngularVelocity(int newV) = 0; 

  //количество направлений
  virtual int getDirectionsNumber() const = 0;
  virtual void setDirectionsNumber(int newV) = 0; 
};
