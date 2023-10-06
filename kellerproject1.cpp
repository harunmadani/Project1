#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <ctype.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {


    //part 1


    cout << "+-------------------------------------------------+" << endl;
    cout << "|          Computer Science and Engineering       |" << endl;
    cout << "|           CSCE 1030 - Computer Science I        |" << endl;
    cout << "|       Keller Neu kwn0018 kwn0018@my.unt.edu     |" << endl;
    cout << "+-------------------------------------------------+" << endl;


    //part 2&3


    int points = 100;
    enum option {displayLeft = '1', displayRight = '2', guess = '3', change = '4', exit = '5'};
    string userName;
    char check;


    //part 4


   bool checkAlpha = false;
   
   while(cout << "Input your username: " && getline(cin, userName)) {
        bool checkAlpha = false;
        
        for(char check : userName){
            
            if(isspace(static_cast<unsigned char>(check)) || (isalpha(static_cast<unsigned char>(check)))) {
                check = tolower(static_cast<unsigned char>(check));
                checkAlpha = true;
                continue;
            }
            if(!isspace(static_cast<unsigned char>(check)) && (!isalpha(static_cast<unsigned char>(check)))) {
            cout << "Error, username must contain only letter and spaces. Try again." << endl;
            checkAlpha = false;
            break;
            }
            if(checkAlpha = false) break;
        }
        if(checkAlpha != false) {
            transform(userName.begin(), userName.end(), userName.begin(), ::tolower);
            cout << "Welcome " << userName << "!" << endl << endl; 
            break;
            }
   }


    //part 5
   

    int randNum1;
    int randNum2;
    srand(time(NULL));

    do {
    randNum1 = (rand() % 101) + 100; 
    randNum2 = (rand() % 101) + 100;
    }while(randNum1 > randNum2);
    

    //part 6 & 7
    int int1 = -1;
    int int2 = -1;

    cout << int1 << "\t" << int2 << endl << endl;
    cout << "1. Display right number" << endl;
    cout << "2. Display left number" << endl;
    cout << "3. Guess a number in between" << endl;
    cout << "4. Change numbers" << endl;
    cout << "5. Exit" << endl << endl;
    cout << "What is your option?: ";
    

    //part 8
    

    bool userChoice = false;
    do{

    int choice;
    cin >> choice;
    
    switch(choice) {
        case 1:
    
        userChoice = true;
        break;
        case 2:

        userChoice = true;
        break;
        case 3:

        userChoice = true;
        break;
        case 4:

        userChoice = true;
        break;
        case 5:

        userChoice = true;
        break;
        default:
            cout << "Error, invalid choice. Choose 1, 2, 3, 4, or 5: ";
            break;
        }
    }while(userChoice = true);


    return(0);
}