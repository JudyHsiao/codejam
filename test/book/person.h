#ifndef PERSON_H
#define PERSON_H

#include<iostream>

class Person {
public:
    Person()=default;
    Person(const string& n, const string &a, int aa):name(n),address(a),age(aa){};


    const std::string& getName() const {
        return name;
    }
    const std::string& getAddress() const {
        return address;
    }
private:
    std::string name;
    std::string address;
    int age = 0;
};

std::istream &read(std::istream &, Person& ) ;
std::ostream &print(std::ostream &, const Person& );
#endif