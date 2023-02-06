#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
class Person;
std::istream &read(std::istream &is, Person &person);
std::ostream &print(std::ostream &os, const Person &person);
class Person
{
    Person() = default;
    Person(const std::string &s) : name(s){}
    Person(const std::string &s1, const std::string &s2) : name(s1), address(s2){}
    explicit Person(std::istream &is) { read(is, *this); }
    friend std::istream &read(std::istream &is, Person &person);
    friend std::ostream &print(std::ostream &os, const Person &person);

public:
    std::string get_name() const { return name; }
    std::string get_address() const { return address; }

private:
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &person)
{
    return is >> person.name >> person.address;
}

std::ostream &print(std::ostream &os, const Person &person)
{
    os << person.name << " " << person.address;
    return os;
}

#endif