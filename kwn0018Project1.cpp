#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <ctype.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    
    /* Group mates:
    Jose Rubio jcr0377 joserubio2@my.unt.edu
    Jose Fraire jjf0140 josefraire@my.unt.edu
    Harun Madani hs0711 AaronMadini@my.unt.edu
    */

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
    }while(randNum1 >= randNum2);
    

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
    
    int pointsBalance = 100;
    int userGuess;
    bool userChoice = true;
    
    if(pointsBalance >= 0){
    do{

        do{
            if(pointsBalance < 0){
                userChoice = true;
                break;
            }


    int choice;
    cin >> choice;
    
    switch(choice) {
        case 1:
        
        userChoice = true;
        
        if(int1 == randNum1){
            cout << "Error, you can only display one number at a time. Try again: " << endl << endl;
            userChoice = false;
        }
        if(userChoice == false){
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display right number" << endl;
            cout << "2. Display left number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Change numbers" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";
            break;
            cin >> choice;
        }

        else if (userChoice != false){
        int2 = randNum2;
            cout << "A correct guess will give you 1 point, and an incorrect guess will take 10 points away." << endl << endl;
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display right number" << endl;
            cout << "2. Display left number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Change numbers" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";
            break;
            cin >> choice;
        }
        break;

        case 2:
        
        userChoice = true;

        if(int2 == randNum2){
            cout << "Error, you can only display one number at a time. Try again: " << endl << endl;
            userChoice = false;
        }
        if(userChoice == false){
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display right number" << endl;
            cout << "2. Display left number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Change numbers" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";
            break;
            cin >> choice;
        }

        else if (userChoice != false){
        int1 = randNum1;
            cout << "A correct guess will give you 1 point, and an incorrect guess will take 10 points away." << endl << endl;
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display right number" << endl;
            cout << "2. Display left number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Change numbers" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";
            break;
            cin >> choice;
        }
        break;

        case 3:

        cout << endl << "Enter your guess: ";
        cin >> userGuess;

        if(userGuess < randNum2 && userGuess > randNum1 && pointsBalance >= 0){
            if(int1 == randNum1 || int2 == randNum2){
                cout << "You guessed correctly, you get 1 point!" << endl;
                pointsBalance += 1;
                cout << "Your total points balance: " << pointsBalance << endl << endl;
                cout << int1 << "\t" << int2 << endl << endl;
                cout << "1. Display right number" << endl;
                cout << "2. Display left number" << endl;
                cout << "3. Guess a number in between" << endl;
                cout << "4. Change numbers" << endl;
                cout << "5. Exit" << endl;
                cout << "What is your option?: ";
                break;
                cin >> choice;
            }
            if(int1 != randNum1 && int2 != randNum2 && pointsBalance >= 0){
            cout << "You guessed correctly, you get 5 points!" << endl;
            pointsBalance += 5;
            cout << "Your total points balance: " << pointsBalance << endl << endl;
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display right number" << endl;
            cout << "2. Display left number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Change numbers" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";
            break;
            cin >> choice;
            }
        } else if(userGuess >= randNum2 || userGuess <= randNum1 && pointsBalance >= 0){
            if(int1 == randNum1 || int2 == randNum2){
                cout << "You guessed incorrectly, you lose 10 points." << endl;
                pointsBalance -= 10;
                if(pointsBalance < 0){
                cout << endl << "Your total points balance: " << pointsBalance << endl;
                cout << "You have run out of points." << endl;
                cout << "Goodbye " << userName << "!" << endl;
                userChoice = true;
                break;
                }else
                cout << "Your total points balance: " << pointsBalance << endl << endl;
                cout << int1 << "\t" << int2 << endl << endl;
                cout << "1. Display right number" << endl;
                cout << "2. Display left number" << endl;
                cout << "3. Guess a number in between" << endl;
                cout << "4. Change numbers" << endl;
                cout << "5. Exit" << endl;
                cout << "What is your option?: ";
                break;
                cin >> choice;
            }
            if(int1 != randNum1 && int2 != randNum2 && pointsBalance >= 0){
            cout << "You guessed incorrectly, you lose 5 points." << endl;
            pointsBalance -= 5;
            if(pointsBalance < 0){
            cout << endl << "Your total points balance: " << pointsBalance << endl;
            cout << "You have run out of points." << endl;
            cout << "Goodbye " << userName << "!" << endl;
            userChoice = true;
            break;
            }else
            cout << "Your total points balance: " << pointsBalance << endl << endl;
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display right number" << endl;
            cout << "2. Display left number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Change numbers" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";
            break;
            cin >> choice;
            }
        }
        userChoice = true;
        break;

        case 4:

        do {
            randNum1 = (rand() % 101) + 100; 
            randNum2 = (rand() % 101) + 100;
        }while(randNum1 >= randNum2);
        
        pointsBalance -= 1;

        cout << "Generated new numbers." << endl;
        cout << "Your point balance: " << pointsBalance << endl;
        cout << int1 << "\t" << int2 << endl << endl;
        cout << "1. Display right number" << endl;
        cout << "2. Display left number" << endl;
        cout << "3. Guess a number in between" << endl;
        cout << "4. Change numbers" << endl;
        cout << "5. Exit" << endl;
        cout << "What is your option?: ";
        break;
        cin >> choice;

        userChoice = true;
        break;
        
        case 5:
        cout << "Goodbye " << userName << "!" << endl;
        cout << "Your final points balance: " << pointsBalance << endl;
        userChoice = true;
        break;
        default:
            cout << "Error, invalid choice. Choose 1, 2, 3, 4, or 5: ";
            break;
        }

        }while(userChoice == false);

    }while(userChoice == true);
    }

    return(0);
}