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
    Aaron Madani hs0711 AaronMadini@my.unt.edu
    */

    //part 1


    cout << "+-------------------------------------------------+" << endl;
    cout << "|          Computer Science and Engineering       |" << endl;
    cout << "|           CSCE 1030 - Computer Science I        |" << endl;
    cout << "|       Keller Neu kwn0018 kwn0018@my.unt.edu     |" << endl;
    cout << "+-------------------------------------------------+" << endl;


    //part 2&3


    int points = 100;
    enum option {displayLeft = '1', displayRight = '2', guess = '3', change = '4', exit = '5'}; //enumerates variables, used in part 7
    string userName;
    char check; //will be used to check the username for numbers or symbols


    //part 4


   bool checkAlpha = false; //creates boolean variable, while be used in the while loop in order to move the user along different prompts
   
   while(cout << "Input your username: " && getline(cin, userName)) { //get line will get the whole line, including spaces
        bool checkAlpha = false;
        
        for(char check : userName){ //makes check = username
            
            if(isspace(static_cast<unsigned char>(check)) || (isalpha(static_cast<unsigned char>(check)))) { //checks for numbers and spaces
                check = tolower(static_cast<unsigned char>(check)); //makes lowercase
                checkAlpha = true; //since it has spaces/numbers, the name is true
                continue;
            }
            if(!isspace(static_cast<unsigned char>(check)) && (!isalpha(static_cast<unsigned char>(check)))) { //! means it does not equal
            cout << "Error, username must contain only letter and spaces. Try again." << endl;
            checkAlpha = false;
            break;
            }
            if(checkAlpha = false) break; //sends user back to beginning of the loop
        }
        if(checkAlpha != false) {
            transform(userName.begin(), userName.end(), userName.begin(), ::tolower); //changes the username to all lowercase
            cout << "Welcome " << userName << "!" << endl << endl; 
            break;
            }
   }


    //part 5
   

    int randNum1; //these ints will be used as the random number
    int randNum2;
    srand(time(NULL)); //starts the random number generation

    do {
    randNum1 = (rand() % 101) + 100;  //generates the random numbers
    randNum2 = (rand() % 101) + 100;
    }while(randNum1 >= randNum2); //loop will end when randNum2 is greater
    

    //part 6 & 7
    int int1 = -1;
    int int2 = -1;

    cout << int1 << "\t" << int2 << endl << endl; //\t puts space between int1 and 2
    cout << "1. Display right number" << endl;
    cout << "2. Display left number" << endl;
    cout << "3. Guess a number in between" << endl;
    cout << "4. Change numbers" << endl;
    cout << "5. Exit" << endl << endl;
    cout << "What is your option?: ";
    

    //part 8
    
    int pointsBalance = 100; //user's points starts at 100
    int userGuess;
    bool userChoice = true; //creates another boolean value for this loop
    
    if(pointsBalance >= 0){ //if user's points is less than 0, the game will end
    do{

        do{
            if(pointsBalance < 0){ //ends the game if user points are less than 0
                userChoice = true;
                break;
            }


    int choice;
    cin >> choice; //user inputs 1,2,3,4, or 5
    
    switch(choice) {
        case 1:
        
        userChoice = true;
        
        if(int1 == randNum1){ //this is if int1 has already been equaled to randNum1
            cout << "Error, you can only display one number at a time. Try again: " << endl << endl;
            userChoice = false;
        }
        if(userChoice == false){ //asks user to decide again
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

        else if (userChoice != false){ //if user choice does not equal false
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

        if(int2 == randNum2){ //if option 1 has already been chosen
            cout << "Error, you can only display one number at a time. Try again: " << endl << endl;
            userChoice = false;
        }
        if(userChoice == false){ //will make user choose again
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

        else if (userChoice != false){ //does not equal false
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

        if(userGuess < randNum2 && userGuess > randNum1 && pointsBalance >= 0){ //if the guess is between the numbers and points aren't less than 0
            if(int1 == randNum1 || int2 == randNum2){ //if user has shown either randNum
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
            if(int1 != randNum1 && int2 != randNum2 && pointsBalance >= 0){ //if user hasn't shown the randNums
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
        } else if(userGuess >= randNum2 || userGuess <= randNum1 && pointsBalance >= 0){ //if user guesses wrong
            if(int1 == randNum1 || int2 == randNum2){
                cout << "You guessed incorrectly, you lose 10 points." << endl;
                pointsBalance -= 10; //subtracts user's points by 10
                if(pointsBalance < 0){ //if user runs out of point
                cout << endl << "Your total points balance: " << pointsBalance << endl;
                cout << "You have run out of points." << endl;
                cout << "Goodbye " << userName << "!" << endl;
                userChoice = true; //will end loop
                break;
                }else
                cout << "Your total points balance: " << pointsBalance << endl << endl; //displays user's balance after losing points
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
            pointsBalance -= 5; //subtracts user's points by 5
            if(pointsBalance < 0){ //if points are less than 0
            cout << endl << "Your total points balance: " << pointsBalance << endl;
            cout << "You have run out of points." << endl;
            cout << "Goodbye " << userName << "!" << endl;
            userChoice = true; //will end loop
            break;
            }else
            cout << "Your total points balance: " << pointsBalance << endl << endl; //displays balance after losing points
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
            randNum1 = (rand() % 101) + 100;  //will choose a different set of random numbers
            randNum2 = (rand() % 101) + 100;
        }while(randNum1 >= randNum2); //loop will end if the first number is less than the second
        
        pointsBalance -= 1; //doing this subtracts user's points by 1

        cout << "Generated new numbers." << endl;
        cout << "Your point balance: " << pointsBalance << endl; //shows balance after subtracted by 1
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
        break; //ends game
        default: //if user doesn't choose 1,2,3,4, or 5
            cout << "Error, invalid choice. Choose 1, 2, 3, 4, or 5: ";
            break;
        }

        }while(userChoice == false); //if it is false the loop will continue

    }while(userChoice == true); //if it is true the loop will end
    }

    return(0);
}