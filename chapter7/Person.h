#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

struct Person{
    std::string name;
    std::string address;

    std::string get_name() const{return name;}
    std::string get_address() const{return address;}
};

std::istream &read(std::istream &is, Person &person){
    return is >> person.name >> person.address;
}

std::ostream &print(std::ostream &os, const Person &person){
        os << person.name << " " << person.address;
        return os;
}

#endif