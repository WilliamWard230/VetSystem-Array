#ifndef LabStorage_H
#define LabStorage_H

#include "LabPet.h"
using namespace std;

class PetStorage{           //storage class 
    public:
        Pet* myPets[10];                // array created from constructor
        PetStorage(){
            Pet* myPet = new Pet();
            myPets[0] = myPet;
        }

        
};
void printPets(PetStorage *myPetsStorage, int count);
void printChoicePet(PetStorage *myPetsStorage, int choice);
void setInfo(PetStorage *myPetsStorage, int count);
int dogfile(PetStorage* myPetsStorage);
int addNewPet(PetStorage* myPetsStorage, int count);
#endif