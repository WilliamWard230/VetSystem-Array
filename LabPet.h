#ifndef LabPet_H
#define LabPet_H
#include <iostream>
using namespace std;

class Pet{          //data class
    private:
        string type;
        string age;
        string name;

    public:
        Pet(){                  // default constructor
            type = "dog";
            name = "doggo";
            age = "5";
        }
        Pet(string givenType, string givenName, string givenAge){       // constructor
            type = givenType;
            name = givenName; 
            age = givenAge;
        }
        string getName();       // these are the getters
        string getType();
        string getAge();
        void setName(string updatedName);           // these are the setters
        void setAge(string updatedAge);

};
#endif