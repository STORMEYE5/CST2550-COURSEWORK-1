#ifndef _VANS_H
#define _VANS_H

#include "vehicles.h"

class Vans: public Vehicle
{
private:
  std::string engine_size;
  int num_seats;
  std::string luggage_space;
  
public:
  void setVanEngine(std::string engine_size){
    this->engine_size = engine_size;
  }
  void setVanSeat(int num_seats){
    this->num_seats = num_seats;
  }
  void setVanLuggage(std::string luggage_space){
    this->luggage_space = luggage_space;
  }

  std::string getVanEngine(){
    return engine_size;
  }
  int getVanSeat(){
    return num_seats;
  }
  std::string getVanLuggage(){
    return luggage_space;
  } 
};

#endif