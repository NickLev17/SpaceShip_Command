#include "../../include/Commands/ChangeVelocityCommand.h"

ChangeVelocityCommand::ChangeVelocityCommand(IMovingObject& mov_obj,IRotatingObject& rot_obj) : _mov_obj(mov_obj), _rot_obj(rot_obj)
{

       // std::cout << " Constructor CheckFuelCommand " <<obj.get()->getFuel();
       std::cout << " Constructor ChangeVelocityCommand";
}

void ChangeVelocityCommand::execute()
{
         
      int newAngle = _rot_obj.getDirection();
     int angularVelocity=_rot_obj.getAngularVelocity();


 // Вычисляем новое направление
        int newDirection=(_rot_obj.getDirection()+_rot_obj.getAngularVelocity())%_rot_obj.getDirectionsNumber();
       
           // Устанавливаем новое направление
       _rot_obj.setDirection(newDirection);
       
       

        // Получаем прямую ссылку на вектор скорости
        std::vector<Point>& velocity=_mov_obj.getVelocity();
   



   //to do
        
}


       
    

    

      
