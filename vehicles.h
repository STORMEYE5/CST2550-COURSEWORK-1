#ifndef _VEHICLES_H
#define _VEHICLES_H

#include <iostream>
#include <string>

class Vehicle
{
private:
  int price;
  std::string make;
  std::string model;
  std::string reg_num;
  std::string colour;
  std::string available;
  std::string return_Date;

public:
  void setMake(std::string make){    
    this->make = make;
  }
  void setModel(std::string model){
    this->model = model;
  }
  void setRegistration(std::string reg_num){
    this->reg_num = reg_num;
  }
  void setColour(std::string colour){
    this->colour = colour;
  }
  void setPrice(int price){
    this->price = price;
  }
  void setAvailable(std::string available){
    this->available = available;
  }
  void setReturn(std::string return_Date){
    this->return_Date = return_Date;
  }
  

  std::string getMake(){
    return make;
  }
  std::string getModel(){
    return model;
  }
  std::string getRegistration(){
    return reg_num;
  }
  std::string getColour(){
    return colour;
  }
  int getPrice(){
    return price;
  }
  std::string getAvailable(){
    return available;
  }
  std::string getReturn(){
    return return_Date;
  }
};

#endif
