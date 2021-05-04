
#include "Kunde.h"

using namespace Client;

Kunde::Kunde(string username) // username must be unique
{
    this->username=username;
    this->favourite_list={};
}


void Kunde::add_favourite(Car new_car) {

    this->favourite_list.push_back(new_car);
}

bool Kunde::delete_favourite(Car new_car) {

    for(int i=0;i<this->favourite_list.size();i++)
    {
        if(this->favourite_list[i].checker(new_car))
        {
            for(int j=i;j<this->favourite_list.size()-1;j++)
            {
                this->favourite_list[j]=this->favourite_list[j+1];
            }
            this->favourite_list.pop_back();
            return true;
        }
    }
    this->favourite_list.pop_back();
}

vector<Car> Kunde::show_all() {

    return this->favourite_list;
}
