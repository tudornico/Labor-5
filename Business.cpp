#include "Business.h"

using namespace Controller;

CarController::CarController() {
    this->_repo = {};
}

void CarController::add(const Car &car) {
    this->_repo.add(car);
}

bool CarController::remove(const Car &car) {
    return this->_repo.remove(car);

}

bool CarController::find(const Car &car) {
    if (this->_repo.find(car))
        return true;
    return false;
}

void CarController::update_Kilometers(Car &car, int _kilometers) {
    this->_repo.update_Kilometers(car, _kilometers);
}

void CarController::update_Price(Car &car, int _price) {
    this->_repo.update_Price(car, _price);
}

vector<Car> CarController::getAll() { // use a copy of the list in the controller
    return this->_repo.get_All();
}

vector<Car> CarController::findBrand(const string &brand) {
    vector<Car> result;
    vector<Car> copy_list;
    copy_list = getAll();
    for (int i = 0; i < copy_list.size(); i++) {
        if (copy_list[i].get_Brand() == brand)
            result.push_back(copy_list[i]);
    }
    return result;

}

vector<Car> CarController::findModel(string model) {
    vector<Car> result;
    vector<Car> copy_list;
    copy_list = getAll();
    for(int i=0;i<copy_list.size();i++)
    {
        if(copy_list[i].get_Model()==model)
            result.push_back(copy_list[i]);
    }
    return result;
}

vector<Car> CarController::findBrandAndModel(const string &brand, const string &model) {
    vector<Car> result;
    vector<Car> copy_list;
    copy_list = getAll();
    for(int i=0;i<copy_list.size();i++)
    {
        if(copy_list[i].get_Brand()==brand && copy_list[i].get_Model()==model)
            result.push_back(copy_list[i]);
    }
    return result;

}

vector<Car> CarController::filterByAge(int age) {
    vector<Car> result;
    vector<Car> copy_list;
    copy_list = getAll();
    for(int i=0;i<copy_list.size();i++)
    {
        if(copy_list[i].get_Year()==age)
            result.push_back(copy_list[i]);
    }
    return result;
}

vector<Car> CarController::filterByKilometers(int kilometers) {
    vector<Car> result;
    vector<Car> copy_list;
    copy_list = getAll();
    for(int i=0;i<copy_list.size();i++)
    {
        if(copy_list[i].get_Kilometers()==kilometers)
            result.push_back(copy_list[i]);
    }
    return result;
}

vector<Car> CarController::filterByAgeAndKilometers(int age, int kilometers) {

    vector<Car> result;
    vector<Car> copy_list;
    copy_list = getAll();
    for(int i=0;i<copy_list.size();i++)
    {
        if(copy_list[i].get_Year()== age&& copy_list[i].get_Kilometers()==kilometers)
            result.push_back(copy_list[i]);
    }
    return result;
}

vector<Car> CarController::sortByPrice(int price) {
    vector<Car> copy_list;
    copy_list = getAll();
    for(int i=0;i<copy_list.size()-1;i++)
    {

        for(int j=i;j<copy_list.size();j++)
        {
            if(copy_list[i].get_Price()>copy_list[j].get_Price())
                swap(copy_list[i],copy_list[j]);
        }
    }
    return copy_list;
}

