#include "Persistence.h"

using namespace Repository;

CarRepo::CarRepo() {
    this->list={};
}

void CarRepo::add(const Car &car) {

    this->list.push_back(car);
}

bool CarRepo::remove(const Car &car) {

    for(int i=0;i<this->list.size()-1;i++)
    {
        if(this->list[i].checker(car))
        {
            for(int j=i;j<this->list.size()-1;j++)
                this->list[j]=this->list[j+1];

            this->list.pop_back();
            return true;
        }
    }
    this->list.pop_back();
    return true;
}

bool CarRepo::find(const Car &car) {

    for(int i=0;i<this->list.size();i++)
    {
        if(this->list[i].checker(car))
            return true;
    }
    return false;
}

void CarRepo::update_Kilometers(Car &car, int _kilometers) {

    if(find(car)== false)
        throw exception();

    for(int i=0;i<this->list.size();i++)
    {
        if(this->list[i].checker(car))
        {
            this->list[i].set_Kilometers(_kilometers);
        }
    }

}


void CarRepo::update_Price(Car &car, int _price) {

    if(find(car)==false)
        throw exception();

    for(int i=0;i<this->list.size();i++)
    {
        if(this->list[i].checker(car))
            this->list[i].set_Price(_price);
    }

}


vector<Car> CarRepo::get_All() {
    return this->list;
}

CarRepo::~CarRepo()=default;
