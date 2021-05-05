#pragma once
#include <iostream>
using namespace std;

namespace Domain
{
  class Car
  {
  public:
    Car(const string &, const string &, const string &, const int &, const int &, const int &, const int &);
    string get_Model();
    string get_Brand();
    int get_Year();
    int get_Kilometers();
    int get_Price();
    int get_Power();
    string get_Fuel();
    void set_Kilometers(int _kilometers);
    void set_Price(int _price);
    bool checker(Car other);
    friend ostream &operator<<(ostream &os, const Car &car);
    ~Car();

  private:
    string model;
    string brand;
    string fuel;
    int yearOfRegistration;
    int kilometers;
    int price;
    int power;
  };
};