#include "./Interfaces/IFuelObject.h"
#include "./Interfaces/IMovingObject.h"
#include "./Interfaces/IRotatingObject.h"

class SpaceShip : public IFuelObject, public IMovingObject, public IRotatingObject
{
private:

    double fuelLevel = 0;
    Point _position;
    vector<Point> _velocity;
    int _direction;
    int _angularVelocity;
    int _directionNumber;
    double _stepFuel; // шаг уменьшения топлива (скорость расхода топлива)

public:
    SpaceShip(double fuel);

    // Реализуем методы из интерфейса IFuelObject
    void setFuel(double amount) override;
    double getFuel() const override;

    // Реализуем методы из интерфейса IMovingObject
    Point getPosition() const override;
    void setPosition(Point newPos) override;
    vector<Point>& getVelocity() override;

    // Реализуем методы из интерфейса IRotatingObject
    double getStepFuel() const override;
    void setStepFuel(double step) override;

    // текущее направление
    int getDirection() const override;
    void setDirection(int newV) override;

    // угловая скорость
    void setAngularVelocity(int newV) override;
    int getAngularVelocity() const override;

    // количество направлений
    void setDirectionsNumber(int newV) override;
    int getDirectionsNumber() const override;
};
