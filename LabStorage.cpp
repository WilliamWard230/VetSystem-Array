#include "LabPet.h"
#include "LabStorage.h"
#include <fstream>
char delimiter = ',';

// function to print array of pets ((uses getters))
void printPets(PetStorage *myPetsStorage, int count){
    string tempPetName = myPetsStorage -> myPets[count] -> getName();
    cout << count+1 << "." << tempPetName << endl;
}
// function to pick a selected pet from array ((uses getters))
void printChoicePet(PetStorage *myPetsStorage, int choice){
    string tempPetType = myPetsStorage -> myPets[choice] -> getType();
    string tempPetName = myPetsStorage -> myPets[choice] -> getName();
    string tempPetAge = myPetsStorage -> myPets[choice] -> getAge();
    cout  << "Type: " << tempPetType << endl;
    cout  << "Name: " << tempPetName << endl;
    cout  << "Age: " << tempPetAge << endl;
}
//function to use adjust a pet's info ((uses setters))
void setInfo(PetStorage *myPetsStorage, int count){
    int choice;
    int option;

    string updatedName;
    string updatedAge;
        for(int x=0; x <= count; x++){
            if(x==0)
            {
                cout << "*****************************";
                cout << "\nList of Pets: \n";
            }
            printPets(myPetsStorage, x);
        }
    cout << "\nSelect a Pet: ";
    cin >> choice;
    while(choice <1 || choice > count+1 || cin.fail() ){
        cin.clear();
        cin.ignore();
        cout << "Please enter a number between 1 and " << count+1 << endl;
        cin >> choice;
    }
    cout << "\nWould you like to update the pet's name or age?" << endl;
    cout << "1: Update Pet's Name \n";
    cout << "2: Update Pet's Age\n";
    cout << "Enter Choice: ";
    cin >> option;
    while (option < 1 || option > 2 || cin.fail())
    {
        if (cin.fail())
        {
            cout << "\nOops! Please enter a number." << endl;
            cin.clear();
            cin.ignore();
            cout << "\nWould you like to update the pet's name or age?" << endl;
            cout << "1: Update Pet's Name \n";
            cout << "2: Update Pet's Age\n";
            cin >> option;
        }
        else
        {
            cout << "\nOpps! Please enter 1 or 2!" << endl;
            cout << "\nWould you like to update the pet's name or age?" << endl;
            cout << "1: Update Pet's Name \n";
            cout << "2: Update Pet's Age\n";
            cin >> option;
        }
    }
    switch(option){
        case 1:
            cout << "Enter updated name: ";
            cin >> updatedName;
            myPetsStorage -> myPets[choice-1] -> setName(updatedName);
            break;
        case 2:
            cout << "Enter updated age: ";
            cin >> updatedAge;
            cin.ignore();
            myPetsStorage -> myPets[choice-1] -> setAge(updatedAge);
            break;
        default:
            break;
    }
}
// Function reads in information from a text file and uses a constructor to create a pet object that is sent to an array
int dogfile(PetStorage* myPetsStorage){
    Pet* tempPet;
    string testString;
    string type; 
    string age; 
    string name;
    int pos = 0;
    char delimiter = ',';
    int count = 0;

    ifstream file("VetPetInfo.txt");

    file >> testString;
    while ((pos = testString.find(delimiter)) != std::string::npos) {

    int typeEnd = testString.find(delimiter);
    type = testString.substr(0, typeEnd);
    testString.erase(0, typeEnd +1);

    int nameEnd = testString.find(delimiter);
    name = testString.substr(0,nameEnd);
    testString.erase(0, nameEnd+1);

    int ageEnd = testString.find(delimiter);
    age = testString.substr(0,ageEnd);
    testString.erase(0, ageEnd+1);

    count += 1;

    tempPet = new Pet(type, name, age);
    myPetsStorage -> myPets[count] = tempPet;
    }
    file.close();
    return count;
}
// function to add a new pet after text file has been read in
int addNewPet(PetStorage* myPetsStorage, int count)
{
Pet* newtempPet;
string type;
string name;
string age;

    cout << "Pets type: ";
    cin.ignore();
    getline(cin, type);
    cout << "Pets name: ";
    getline(cin, name);
    cout << "Pets age: ";
    getline(cin, age);
    
    newtempPet = new Pet(type, name, age);
    myPetsStorage -> myPets[count+1] = newtempPet;

    count ++;

    return count;
}
