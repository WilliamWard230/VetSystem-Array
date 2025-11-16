#include "LabDescription.h"
#include "LabPet.h"
#include "LabStorage.h"
#include <iostream>


void displayPetDescription(int descriptionChoice, int randomDescription, PetStorage *myPetsStorage ){       // other class definition 
    string tempPetType = myPetsStorage -> myPets[descriptionChoice] -> getType();
    string tempPetName = myPetsStorage -> myPets[descriptionChoice] -> getName();
    string tempPetAge = myPetsStorage -> myPets[descriptionChoice] -> getAge();

    switch(randomDescription){
        case 1: 
            cout << tempPetName << " is a " << tempPetAge << " year old " << tempPetType << ". \n";
            cout << tempPetName << " is kind and friendly.\n";
            cout << tempPetName << " has many friends";
            break;
        case 2:
            cout << tempPetName << " is a " << tempPetAge << " year old " << tempPetType << ". \n";
            cout << tempPetName << " is aggressive and not very social. \n";
            cout << tempPetName << " has no friends. \n";
            break;
        case 3:
            cout << tempPetName << " is a " << tempPetAge << " year old " << tempPetType << ". \n";
            cout << tempPetName << " is very goofy. \n";
            cout << tempPetName << " is a staff favorite. \n";
            break;
        default:
            break;
    }
}