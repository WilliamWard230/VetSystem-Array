Program Idea: For our program 1 we want to create a program that can be used in a vet office. The program will read in a text file and pass the input into substrings. The substrings consisting of a pet's type, name and age, will be pushed to an array of pointers that we can interact with. We will be able to adjust names and ages of pets. We will have a menu for interacting with this array. We will be able to adjust a pet's name or age. We will also be able to select a pet and print a pet description. We may also have a class to assign procedures to pets, depending upon if the pet description class fulfills the 'other' class requirement. 

Classes and included Functions:

class Pet{          //This is the data class
    public:
        Pet(){              //Default Constructor
            type = "Dog";
            name = "Doggy";
            age = 3;
            price = 5.99;
        }
        Pet(string type, string name, int age, double price = 5.99){        //constructor .... Price has a default value incase we don't pass a value
            type = type;
            name = name;
            age = age;
            price = price;
        }
        string getPet(string str);
        void setName();                 //Function to update a pet's name
        void setAge();                  //Function to update a pet's age
        
    private:
        string type;
        string name;
        int age;
        double price;

};

class PetStorage{           //This is the storage class
    public:
        string parsingMethod();     //Used to parse the text file being read in
        Pet** petArrayPtr[];
};

class PetDescription{
    void description(string name){          //helper class that will return one of three descriptions at random

    };
};

// class Procedure {            // We might not need this class, but I kept it in as an option. 
//     public:                  // to simplify the neccessary code I figured we could dumb down 
//         string name;         // the project and go with a pet description as the third class. 
//         string procedure;    // I'm open to any discussion. 
// };

<!-- will keep inventory of animals checked in and keep a balance of charges. The program will also have options for different procedurs along with their cost. It will then print out your charges after check out.  -->

<!-- The program will start with a menu that has the options for check in or check out. When the user chooses check in, the program will starting reading to a .txt file about your animal and etc. If the user chooses check out, then it will read from the .txt file and allow the user to choose which animal is theirs. Once the user chooses their animal and what operations were done, thier charges and operations will be printed. -->

Program Plan (temporary):