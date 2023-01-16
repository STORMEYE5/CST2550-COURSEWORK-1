#ifndef _MOTORCYCLES_H
#define _MOTORCYCLES_H

#include "vehicles.h"


class Motorcycles: public Vehicle
{
private:
  int engine_size;
  std::string passenger_seat;
  std::string luggage_space;

public:
  void setCycleEngine(int engine_size){
    this->engine_size = engine_size;
  }
  void setCycleSeat(std::string passenger_seat){
  this->passenger_seat = passenger_seat;   
  }
  void setCycleLuggage(std::string luggage_space){
    this->luggage_space = luggage_space;
  }

  int getCycleEngine(){
    return engine_size;
  }
  std::string getCycleSeat(){
    return passenger_seat;
  }
  std::string getCycleLuggage(){
    return luggage_space;
  }  
};

#endif