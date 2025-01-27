#pragma once
#include "Business.h"
#include <iostream>
using namespace std;
using namespace Controller;

namespace UI{
  class Console
  {
  private:
    CarController & _ctrl;

    //methods of car repo
    void add(const Car &car);
    bool remove(const Car &car);
    bool find(const Car &car);
    void update_Kilometers(Car &car, int _kilometers); 
    void update_Price(Car &car, int _price);           
    vector<Car> getAll();

    //individual methods of controller
    vector<Car> findBrand(string brand);
    vector<Car> findModel(string model);
    vector<Car> findBrandAndModel(string brand, string model);
    vector<Car> filterByAge(int age);
    vector<Car> filterByKilometers(int kilometers);
    vector<Car> filterByAgeAndKilometers(int age, int kilometers);
    vector<Car> sortByPrice(int price);

  public:
    Console(CarController &);

    void run();
  };
};