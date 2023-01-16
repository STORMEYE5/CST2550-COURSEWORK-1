#include "vehicles.h"
#include "Motorcycles.h"
#include "Cars.h"
#include "Vans.h"
#include <fstream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <iomanip>
#include <cmath>

// VARIABLE DECLARATIONS
int number = 0;
int count = 0;
char number2;
bool condition = true;
std::string textSample;
std::string textSample2;
std::string temp_var;
std::string temp_var2;
std::string file_name;

std::vector<std::string> arrayList;
std::vector<int> num;
std::vector<std::string> sub_string;

std::string make;
std::string model;
std::string colour;
std::string registration;
bool available;
std::string date;
std::string cycleSeat;
std::string cycleLuggage;
int seat;
std::string luggage;
int price;
std::string engine_size;
int doors;
int cycle_engine;

// CREATING CLASS OBJECTS
Motorcycles motorcycle;
Cars car;
Vans van;

// FUNCTION TO CHECK IF INPUT HAS NO NUMBERS
bool check_string_input(std::string str_input){
  int length = str_input.length();
  char* char_str = new char[length];
  strcpy(char_str, str_input.c_str());
  for (int x = 0; x < length; x++){
    int check;
    check = isalpha(char_str[x]);
    if (check == 0){
      std::cout << "INVALID INPUT";
      return false;
    } else {
      continue;
    }
  }
  return true;
}

// FUNCTION TO CHECK IF INPUT DOES NOT CONTAIN LETTERS
bool check_input_int(int int_input){
  std::string t = std::to_string(int_input);
  int length = t.size();
  char const *char_int = t.c_str();;
  char_int = t.c_str();
  for (int x = 0; x < length; x++){
    int check;
    check = isdigit(char_int[x]);
    if (check == 0){
      std::cout << "INVALID INPUT";
      return false;
    } else {
      continue;
    }
  }
  return true;
}

bool check_int_input(std::string str_input){
  int length = str_input.length();
  char* char_str = new char[length];
  strcpy(char_str, str_input.c_str());
  for (int x = 0; x < length; x++){
    int check;
    if (char_str[x] == '.') {
      continue;
    } else {
      check = isdigit(char_str[x]);
      if (check == 0){
        std::cout << "INVALID INPUT";
        return false;
      } else {
        continue;
      }
    }    
  }
  return true;
}

// FUNCTION TO SET VALUES IN THE VARIABLES FOR MOTORCYCLE OBJECT
void setters_motorcycle(){
  std::cout << "ENTER BIKE MAKE: ";  
  std::cin >> make;
  if (!check_string_input(make)){
    return;
  }
  motorcycle.setMake(make);	    
  std::cout << "ENTER BIKE MODEL: ";
  std::cin >> model;
  if (!check_string_input(model)){
    return;
  }
  motorcycle.setModel(model);
  std::cout << "ENTER BIKE PRICE: ";
  std::cin >> price;
  if (!check_input_int(price)){
    return;
  }
  motorcycle.setPrice(price);
  std::cout << "ENTER ENGINE SIZE(IN CC): ";
  std::cin >> cycle_engine;
  if (!check_input_int(cycle_engine)){
    return;
  }
  motorcycle.setCycleEngine(cycle_engine);
  std::cout << "IS THERE A PASSENGER SEAT? (Yes/No): ";
  std::cin >> cycleSeat;
  if (cycleSeat == "Yes"){
    motorcycle.setCycleSeat("Passenger seat");
  } else if (cycleSeat == "No"){
    motorcycle.setCycleSeat("No passenger");
  } else {
    std::cout << "INVALID INPUT" << std::endl;
    return;
  }
  std::cout << "DOES MOTORCYCLE HAVE LUGGAGE(Yes/No): ";
  std::cin >> cycleLuggage;
  if(cycleLuggage == "Yes"){
    motorcycle.setCycleLuggage("Has luggage");
  } else if (cycleLuggage == "No"){
    motorcycle.setCycleLuggage("No luggage");
  } else {
    std::cout << "INVALID INPUT" << std::endl;
    return;
  }
  std::cout << "ENTER REGISTRATION NUMBER: ";
  std::cin >> registration;
  motorcycle.setRegistration(registration);
  std::cout << "ENTER COLOUR OF BIKE: ";
  std::cin >> colour;
  if (!check_string_input(colour)){
    return;
  }
  motorcycle.setColour(colour);
  std::cout << "IS BIKE AVAILABLE(Yes/No): ";
  std::string result;
  std::cin >> result;
  if (result == "Yes"){
    available = true;
  } else if (result == "No") {
    available = false;
  } else {
    std::cout << "INVALID INPUT" << std::endl;
    return;
  }
  motorcycle.setAvailable(result);
  if (available == true) {
    motorcycle.setReturn("N/A");
    return;
  } else {
    std::cout << "ENTER DATE AVAILABLE: ";
    std::cin >> date;
    motorcycle.setReturn(date);
    return;
  }
}

// FUNCTION TO SET VALUES IN THE VARIABLES FOR CAR OBJECT
void setters_car(){
  std::cout << "ENTER CAR MAKE: ";  
  std::cin >> make;
  if (!check_string_input(make)){
    return;
  }
  car.setMake(make);	    
  std::cout << "ENTER CAR MODEL: ";
  std::cin >> model;
  if (!check_string_input(model)){
    return;
  }
  car.setModel(model);
  std::cout << "ENTER CAR PRICE: ";
  std::cin >> price;
  if (!check_input_int(price)){
    return;
  }
  car.setPrice(price);
  std::cout << "ENTER ENGINE SIZE(IN LITRES): ";
  std::cin >> engine_size;
  if (!check_int_input(engine_size)){
    return;
  }
  car.setCarEngine(engine_size);
  std::cout << "ENTER NUMBER OF SEATS: ";
  std::cin >> seat;
  if (!check_input_int(seat)){
    return;
  }
  car.setCarSeat(seat);
  std::cout << "ENTER NUMBER OF DOORS: ";
  std::cin >> doors;
  if (!check_input_int(doors)){
    return;
  }
  car.setCarDoor(doors);
  std::cout << "ENTER REGISTRATION NUMBER: ";
  std::cin >> registration;
  car.setRegistration(registration);
  std::cout << "ENTER COLOUR OF CAR: ";
  std::cin >> colour;
  if (!check_string_input(colour)){
    return;
  }
  car.setColour(colour);
  std::cout << "IS CAR AVAILABLE(Yes/No): ";
  std::string result;
  std::cin >> result;
  if (result == "Yes"){
    available = true;
  } else if (result == "No"){
    available = false;
  } else {
    std::cout << "INVALID INPUT" << std::endl;
    return;
  }
  car.setAvailable(result);
  if (available == true) {
    car.setReturn("N/A");
    return;
  } else {
    std::cout << "ENTER DATE AVAILABLE: ";
    std::cin >> date;
    car.setReturn(date);
    return;
  }
}

// FUNCTION TO SET VALUES IN THE VARIABLES FOR MOTORCYCLE OBJECT
void setters_van(){
  std::cout << "ENTER VAN MAKE: ";  
  std::cin >> make;
  if (!check_string_input(make)){
    return;
  }
  van.setMake(make);	    
  std::cout << "ENTER VAN MODEL: ";
  std::cin >> model;
  if (!check_string_input(model)){
    return;
  }
  van.setModel(model);
  std::cout << "ENTER VAN PRICE: ";
  std::cin >> price;
  if (!check_input_int(price)){
    return;
  }
  van.setPrice(price);
  std::cout << "ENTER ENGINE SIZE(IN LITRES): ";
  std::cin >> engine_size;
  if (!check_int_input(engine_size)){
    return;
  }
  van.setVanEngine(engine_size);
  std::cout << "ENTER NUMBER OF SEATS: ";
  std::cin >> seat;
  if (!check_input_int(seat)){
    return;
  }
  van.setVanSeat(seat);
  std::cout << "ENTER LUGGAGE SPACE: ";
  std::cin >> luggage;
  if (!check_int_input(luggage)){
    return;
  }
  van.setVanLuggage(luggage);
  std::cout << "ENTER REGISTRATION NUMBER: ";
  std::cin >> registration;
  van.setRegistration(registration);
  std::cout << "ENTER COLOUR OF VAN: ";
  std::cin >> colour;
  if (!check_string_input(colour)){
    return;
  }
  van.setColour(colour);
  std::cout << "IS VAN AVAILABLE(Yes/No): ";
  std::string result;
  std::cin >> result;
  if (result == "Yes"){
    van.setAvailable(result);
  } else if (result == "No"){
    van.setAvailable(result);
  } else {
    std::cout << "INVALID INPUT" << std::endl;
    return;
  }
  if (available == true) {
    van.setReturn("N/A");
    return;
  } else {
    std::cout << "ENTER DATE AVAILABLE: ";
    std::cin >> date;
    van.setReturn(date);
    return;
  }
}


void displayCLI_motorcycle();
void displayCLI_car();
void displayCLI_van();

// FUNCTION TO DISPLAY THE DETAILS OF THE VEHICLES
void displayCLI(std::string str3){
  std::cout << "VEHICLE TYPE: " << sub_string.at(0) << std::endl;
  std::cout << "MAKE: " << sub_string.at(1) << std::endl;
  std::cout << "MODEL: " << sub_string.at(2) << std::endl;
  std::cout << "PRICE: " << sub_string.at(3) << std::endl;
  std::cout << "ENGINE SIZE: " << sub_string.at(4) << std::endl;

  if (str3 == "bike"){
    displayCLI_motorcycle();
  } else if (str3 == "car"){
    displayCLI_car();
  } else if (str3 == "van"){
    displayCLI_van();
  }
  
  std::cout << "REGISTRATION NUMBER: " << sub_string.at(7) << std::endl;
  std::cout << "COLOUR: " << sub_string.at(8) << std::endl;
  std::cout << "AVAILABLE: " << sub_string.at(9) << std::endl;
  std::cout << "DATE AVAILABLE: " << sub_string.at(10) << std::endl;
}

// FUNCTION TO DISPLAY SPECIFIC MOTORCYCLE DETAILS
void displayCLI_motorcycle(){
  std::cout << "PASSENGER SEAT: " << sub_string.at(5) << std::endl;
  std::cout << "LUGGAGE SPACE: " << sub_string.at(6) << std::endl;
}

// FUNCTION TO DISPLAY SPECIFIC CAR DETAILS
void displayCLI_car(){
  std::cout << "NUMBER OF SEATS: " << sub_string.at(5) << std::endl;
  std::cout << "NUMBER OF DOORS: " << sub_string.at(6) << std::endl;
}

// FUNCTION TO DISPLAY SPECIFIC VAN DETAILS
void displayCLI_van(){
  std::cout << "NUMBER OF SEATS: " << sub_string.at(5) << std::endl;
  std::cout << "LUGGAGE SPACE: " << sub_string.at(6) << std::endl;
}

// FUNCTION TO DISPLAY A MESSAGE AND REQUEST INPUT TO CONTINUE
void continue_prompt(){
  do {
    std::cin.ignore();
    std::cout << "\nPRESS ENTER TO CONTINUE";
  } while (std::cin.get() != '\n');
}

// FUNCTION TO LOAD FILE INPUT BY USER
int load_file(std::string file_name){
  if (!(arrayList.empty())){
    std::cout << "\nFILE HAS ALREADY BEEN LOADED.\n";
    return 1;
  }

  std::ifstream FileReader(file_name); 

  while (std::getline(FileReader, textSample)){
    arrayList.push_back(textSample);
  }

  std::cout << "FILE HAS BEEN LOADED SUCCESSFULLY" << std::endl;
  return 0;
}

// FUNCTION TO OVERWRITE THE FILE INPUT BY USER
void save_file(){
  std::ofstream FileWriter;
  FileWriter.open(file_name);
  for (std::vector<std::string>::iterator i=arrayList.begin(); i!=arrayList.end(); i++){
    FileWriter << *i << std::endl;
  }
  FileWriter.close();
  std::cout << "\nFILE HAS BEEN SUCCESSFULLY SAVED\n" << std::endl;
}

// FUNCTION TO ADD A VEHICLE BY USER
void add_vehicle(){
  int choice;
  std::cout << "\n\n******CHOOSE TYPE OF VEHICLE:******" << std::endl;
  std::cout << "1: BIKE" << std::endl;
  std::cout << "2: CAR" << std::endl;
  std::cout << "3: VAN" << std::endl;

  std::cout << "\nENTER YOUR CHOSEN OPTION'S NUMBER: ";
  std::cin >> choice;
  
  std::string concat_string;

  switch (choice){
  case 1:
    {
      setters_motorcycle();
      concat_string = "bike:" + motorcycle.getMake() + ":" + motorcycle.getModel() + ":£" + (std::to_string((motorcycle.getPrice()))) + ":" + (std::to_string((motorcycle.getCycleEngine()))) + "cc:" +  motorcycle.getCycleSeat() + ":" + motorcycle.getCycleLuggage()  + ":" + motorcycle.getRegistration() + ":" + motorcycle.getColour() + ":" + motorcycle.getAvailable() + ":" + motorcycle.getReturn();
      arrayList.push_back(concat_string);
      break;
    }
    
  case 2:
    {
      setters_car();
      concat_string = "car:" + car.getMake() + ":" + car.getModel() + ":£" + (std::to_string((car.getPrice()))) + ":" + car.getCarEngine() + "L:" +  (std::to_string((car.getCarSeat()))) + " seats:" + (std::to_string((car.getCarDoors())))  + " door:" + car.getRegistration() + ":" + car.getColour() + ":" + car.getAvailable() + ":" + car.getReturn();
      arrayList.push_back(concat_string);
      break;
    }

  case 3:
    {
      setters_van();
      concat_string = "van:" + van.getMake() + ":" + van.getModel() + ":£" + (std::to_string((van.getPrice()))) + ":" + van.getVanEngine() + "L:" +  (std::to_string((van.getVanSeat()))) + " seats:" + van.getVanLuggage()  + " cubic meters luggage space:" + van.getRegistration() + ":" + van.getColour() + ":" + van.getAvailable() + ":" + van.getReturn();
      arrayList.push_back(concat_string);
      break;
    }
  }
}

// FUNCTION TO REMOVE A SPECIFIC VEHICLE FROM FILE
void remove_vehicle(){
  std::cout << "\nENTER VEHICLE REGISTRATION NUMBER: ";
  std::cin >> temp_var;

  for (auto it = arrayList.begin(); it != arrayList.end(); it++) {
    size_t index = it -> find(temp_var);
    if (index != std::string::npos) {
      arrayList.erase(it);
      break;   
    } else if (std::next(it) == arrayList.end()) {
      std::cout << "VEHICLE NOT FOUND";
      return;
    }
  }
}

// FUNCTION TO DISPLAY SPECIFIC DETAILS OF ALL VEHICLES
void display_details_part(){
  const char separator = ' ';
  const int nameWidth = 15;
  const int specialwidth = 25;

  std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "MAKE";
  std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "MODEL";
  std::cout << std::left << std::setw(specialwidth) << std::setfill(separator) << "REGISTRATION NUMBER";
  std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "AVAILABLE";

  for (std::string str1 : arrayList) {
    num.clear();
    sub_string.clear();
    num.push_back(-1);
    for (int i = 0; i < (int)str1.size(); i++) {
      if (str1[i] == ':') {
        num.push_back(i);
      }
    }

    std::cout << "\n";
    
    for (int i=0; i < (int)num.size(); i++) {
      sub_string.push_back( str1.substr( num[i] + 1, ( num[i + 1] - (num[i] + 1) ) ) );
    }

    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << sub_string.at(1);
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << sub_string.at(2);
    std::cout << std::left << std::setw(specialwidth) << std::setfill(separator) << sub_string.at(7);
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << sub_string.at(9);
  }
}

// FUNCTION TO DISPLAY ALL DETAILS OF A SPECIFIC VEHICLE
void display_details_full(){
  std::cout << "\nENTER VEHICLE REGISTRATION NUMBER: ";
  std::cin >> temp_var;
  std::string display_string;
  int count = 1;

  for (std::string str4 : arrayList) {
    num.clear();
    sub_string.clear();
    num.push_back(-1);
    for (int i = 0; i < (int)str4.size(); i++) {
      if (str4[i] == ':') {
        num.push_back(i);
      }
    }
    
    for (int i=0; i < (int)num.size(); i++) {
      sub_string.push_back( str4.substr( num[i] + 1, ( num[i + 1] - (num[i] + 1) ) ) );
    }

    if (sub_string.at(7) == temp_var) {
      display_string = str4;
      break;   
    } 
    else if (count == (int)arrayList.size()){
      std::cout << "\nVEHICLE NOT FOUND\n";
      return;
    }
    count++;
  }

  num.clear();
  sub_string.clear();
  num.push_back(-1);
  for (int i = 0; i < (int)display_string.size(); i++) {
    if (display_string[i] == ':') {
      num.push_back(i);
    }
  }

  std::cout << "\n";
  
  for (int i=0; i < (int)num.size(); i++) {
    sub_string.push_back( display_string.substr( num[i] + 1, ( num[i + 1] - (num[i] + 1) ) ) );
  }

  if (sub_string.at(0) == "bike"){
    number2 = 1;
  } else if (sub_string.at(0) == "car"){
    number2 = 2;
  } else if (sub_string.at(0) == "van"){
    number2 = 3;
  }

  switch (number2) {
  case 1:
    {
      displayCLI("bike");
      break;
    }
  case 2:
    {
      displayCLI("car");
      break;
    }
  case 3:
    {
      displayCLI("van");
      break;
    }
  }
}

// FUNCTION TO SAVE FILE UPON EXITING PROGRAM
void save_change(){
  std::string file_change;
  std::cout << "FILE HAS BEEN MODIFIED\nEXIT WITHOUT SAVING TO DISCARD CHANGES\nDO YOU WISH TO SAVE THE CHANGES? (Yes/No)" << std::endl;
  std::cin >> file_change;
  if (file_change == "Yes"){
    save_file();
    return;
  } else if (file_change == "No"){
    return;
  } else {
    std::cout << "\nINVALID INPUT\n" << std::endl;
    return;
  }
}

// FUNCTION TO EXIT PROGRAM
void exit_program(){
  std::ifstream FileCompare(file_name);
  std::vector<std::string> compare_vector;

  while (std::getline(FileCompare, textSample2)){
    compare_vector.push_back(textSample2);
  }

  if (compare_vector.size() == arrayList.size()) {
    for (int y = 0; y < (int)arrayList.size(); y++) {
      if (compare_vector[y] != arrayList[y]){
        save_change();
        break;
      }
    }
  } else if (compare_vector.size() != arrayList.size()){
    save_change();
  }

  condition = false;
}

// FUNCTION TO DISPLAY THE MENU FOR USER TO CHOOSE
void menu(){
  while (condition == true){
    std::cout << "\n\n******CHOOSE FROM OPTIONS AVAILABLE:******";
    std::cout << "\n1: LOAD VEHICLES FROM FILE";
    std::cout << "\n2: SAVE VEHICLES TO FILE";
    std::cout << "\n3: ADD VEHICLE";
    std::cout << "\n4: REMOVE VEHICLE";
    std::cout << "\n5: LIST ALL VEHICLES";
    std::cout << "\n6: DISPLAY ALL DETAILS OF A VEHICLE";
    std::cout << "\n7: EXIT";

    std::cout << "\n\nENTER THE CHOSEN OPTION'S NUMBER: ";
    std::cin >> number;

    if (number < 1 || number > 7){
      std::cout << "\n\n";
      menu();
    } else {
      switch(number){
      case 1:
        {
          std::cout << "NAME OF FILE: ";
          std::cin >> file_name;
          load_file(file_name);
          continue_prompt();
          break;
        }
      case 2:
        {
          save_file();
          continue_prompt();
          break;
        }
      case 3:
        {
          add_vehicle();
          continue_prompt();
          break;
        }
      case 4:
        {
          remove_vehicle();
          continue_prompt();
          break;
        }
      case 5:
        {
          display_details_part();
          continue_prompt();
          break;
        }
      case 6:
        {
          display_details_full();
          continue_prompt();
          break;
        }
      case 7:
        {
          exit_program();
          break;
        }
      }
    }
  }
  return;
}
