//Group members: William Ward, Nathan Lopp, Elliot Lovins, Bernie Friesel
//Lab1
//10/04/2024
#include <iostream>
#include <fstream>
#include "LabStorage.h"
#include "LabPet.h"
#include "LabDescription.h"

using namespace std;

int main()
{
    srand(time(0));
    int count = 0;
    int choice;
    int menuChoice;
    int randomDescription = (rand() % 3) + 1;
    PetStorage *myPetsStorage = new PetStorage();

    count = dogfile(myPetsStorage); // Reads in txt file and constructs pet object using constructor from data class(labpet) returns a count for # of pets

    do
    {
        cout << "\n\nWelcome to our Veterinary Office! What would you like to do today?" << endl;
        cout << "1. View the Pets in the Kennel" << endl;
        cout << "2. Add a Pet to the Kennel" << endl;
        cout << "3. Update Pet Info" << endl;
        cout << "4. Leave the Clinc" << endl;
        cin >> menuChoice;

        while (menuChoice < 1 || menuChoice > 4 || cin.fail())
        {
            if (cin.fail())
            {

                cout << "\nOops! please enter a number" << endl;
                cin.clear();
                cin.ignore();
                cout << "\nWelcome to our Veterinary Office! What would you like to do today?" << endl;
                cout << "1. View the Pets in the Kennel" << endl;
                cout << "2. Add a Pet to the Kennel" << endl;
                cout << "3. Update Pet Info" << endl;
                cout << "4. Leave the Clinc" << endl;
                cin >> menuChoice;
            }
            else
            {
                cout << "\nOops! you entered an invalid choice! Please enter 1, 2, or 3!" << endl;
                cout << "\nWelcome to our Veterinary Office! What would you like to do today?" << endl;
                cout << "1. View the Pets in the Kennel" << endl;
                cout << "2. Add a Pet to the Kennel" << endl;
                cout << "3. Update Pet Info" << endl;
                cout << "4. Leave the Clinc" << endl;
                cin >> menuChoice;
            }
        }
        switch (menuChoice)
        {
        case 1:
            for (int x = 0; x <= count; x++)
            {
                if (x == 0)
                {
                    cout << "*****************************";
                    cout << "\nList of Pets: \n";
                }
                printPets(myPetsStorage, x);
            }

            cout << "\nEnter number of the pet you wish to interact with: ";
            cin >> choice;
            
            while(choice < 1 || choice > count+1 || cin.fail())
            {
                if (cin.fail())
                {
                    cout << "\nOops! please enter a number" << endl;
                    cin.clear();
                    cin.ignore();
                    cout << "Which pet would you like to interact with? " << endl;
                    cin >> choice;
                }
                else
                {
                    cout << "Please choose a valid input. \n";
                    cout << "Which pet would you like to interact with? " << endl;
                    cin >> choice;
                }
            }
            printChoicePet(myPetsStorage, choice - 1);
            randomDescription = (rand() % 3) + 1;
            displayPetDescription(choice - 1, randomDescription, myPetsStorage);
            break;

        case 2:
            count = addNewPet(myPetsStorage, count);
            break;

        case 3:
            setInfo(myPetsStorage, count);
            break;

        case 4:
            cout << "\nHave a fantastic day!" << endl;
            delete myPetsStorage;       // memory management
            return 0;
            break;
            
        }
    } while (menuChoice != 4);
}