#include <iostream>
//#include <string>
#include <cmath>
#include <cctype>
#include <ctype.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

    /* Group mates:
    Keller Neu kwn0018 kellerneu@my.unt.edu
    Jose Rubio jcr0377 joserubio2@my.unt.edu
    Jose Fraire jjf0140 josefraire@my.unt.edu
    Aaron Madani hs0711 AaronMadini@my.unt.edu
    */

   //part 2
   const int row = 5;
   const int col = 5;
   enum option {displayLeft = '1', displayRight = '2', guess = '3', reset = '4', exitGame = '5'};


    //part 3
   string getName(string userName)
    {
        
        bool checkAlpha = false;

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
        
        return userName;
    }

    //part 4
    int genShowMatrix(int visArray[][col])
    {
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                visArray[i][j] = -1;
            }
        }
        return visArray[row][col];
    }

    //part 5
    int genHideMatrix(int hiddenArray[][col], int randNum1, int randNum2)
    {
        for(int i=0; i<row; i++)
        {

            for(int j=0; j<col; j++)
            {
                do{
                hiddenArray[i][j] = (rand() % 200) + 100;
                }while(hiddenArray[i][j] < randNum1 || hiddenArray[i][j] > randNum2);
            }
        }
        

        return hiddenArray[row][col];
    }

    //part 6
    void showMatrix(int visArray[][col])
    {
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                cout << visArray[i][j] << " ";
            }
            cout << endl;
        }

        return;
    }

    //part 7
    void setdisplayLeft(int hiddenArray[][col], int visArray[][col], int randNum1, int int1, int int2)
    {
        int1 = randNum1;
            cout << "A correct guess will give you 1 point, and an incorrect guess will take 10 points away." << endl << endl;
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display right number" << endl;
            cout << "2. Display left number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Change numbers" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";

        return;
    }

    //part 8
    void setdisplayRight(int hiddenArray[][col], int visArray[][col], int randNum2, int int1, int int2)
    {
        int2 = randNum2;
            cout << "A correct guess will give you 1 point, and an incorrect guess will take 10 points away." << endl << endl;
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display right number" << endl;
            cout << "2. Display left number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Change numbers" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";
            
        return;
    }

    //part 9
    void eliminate(int rowIndex, int colIndex, int visArray[][col])
    {
        
        return;
    }

    //part 10
    bool allZeros(int visArray[][col], bool isZero)
    {

        return isZero;
    }

    //part 11
    void funcGuess()
    {

        return;
    }

    //part 12
    void initialize(int randNum1, int randNum2, int visArray[][col], int hiddenArray[][col])
    {
        srand(time(NULL));
        randNum1 = (rand() % 100) + 100;  //generates the random numbers
        randNum2 = (rand() % 100) + 200;

        visArray[row][col] = genShowMatrix(visArray);

        hiddenArray[row][col] = genHideMatrix(hiddenArray, randNum1, randNum2);

        return;
    }


int main() {

    //part 1
    cout << "+-------------------------------------------------+" << endl;
    cout << "|          Computer Science and Engineering       |" << endl;
    cout << "|           CSCE 1030 - Computer Science I        |" << endl;
    cout << "|       Keller Neu kwn0018 kwn0018@my.unt.edu     |" << endl;
    cout << "+-------------------------------------------------+" << endl;

    //part 13
    int userPoints = 100;

    //part 14
    int int1 = -1;
    int int2 = -1;

    //part 15
    int randNum1;
    int randNum2;
    int visArray[row][col];
    int hiddenArray[row][col];
    srand(time(NULL));

    initialize(randNum1, randNum2, visArray, hiddenArray);

    //part 16
    string userName;
    getName(userName);

    //part 17
    int choice;
    
    cout << int1 << "\t" << int2 << endl << endl; //\t puts space between int1 and 2
    cout << "1. Display right number" << endl;
    cout << "2. Display left number" << endl;
    cout << "3. Guess a number in between" << endl;
    cout << "4. Change numbers" << endl;
    cout << "5. Exit" << endl << endl;
    cout << "What is your option?: ";

    cin >> choice;

    //part 19
    bool userChoice = true;
    int userGuess;

    if(userPoints >= 0){ //if user's points is less than 0, the game will end
    do{

        do{
            if(userPoints < 0){ //ends the game if user points are less than 0
                userChoice = true;
                break;
            }

    
    //part 18
    switch(choice) {
        case 1:
        
        userChoice = true;
        
        if(int2 == randNum2){ //this is if int1 has already been equaled to randNum1
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
        
        setdisplayLeft(hiddenArray, visArray, randNum1, int1, int2);

        }
        break;

        case 2:
        
        userChoice = true;

        if(int1 == randNum1){ //if option 1 has already been chosen
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
        
        setdisplayLeft(hiddenArray, visArray, randNum2, int1, int2);
        
        }
        
        break;
        

        case 3:

        cout << endl << "Enter your guess: ";
        cin >> userGuess;

        if(userGuess < randNum2 && userGuess > randNum1 && userPoints >= 0){ //if the guess is between the numbers and points aren't less than 0
            if(int1 == randNum1 || int2 == randNum2){ //if user has shown either randNum
                cout << "You guessed correctly, you get 1 point!" << endl;
                userPoints += 1;
                cout << "Your total points balance: " << userPoints << endl << endl;
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
            if(int1 != randNum1 && int2 != randNum2 && userPoints >= 0){ //if user hasn't shown the randNums
            cout << "You guessed correctly, you get 5 points!" << endl;
            userPoints += 5;
            cout << "Your total points balance: " << userPoints << endl << endl;
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
        } else if(userGuess >= randNum2 || userGuess <= randNum1 && userPoints >= 0){ //if user guesses wrong
            if(int1 == randNum1 || int2 == randNum2){
                cout << "You guessed incorrectly, you lose 10 points." << endl;
                userPoints -= 10; //subtracts user's points by 10
                if(userPoints < 0){ //if user runs out of point
                cout << endl << "Your total points balance: " << userPoints << endl;
                cout << "You have run out of points." << endl;
                cout << "Goodbye " << userName << "!" << endl;
                userChoice = true; //will end loop
                break;
                }else
                cout << "Your total points balance: " << userPoints << endl << endl; //displays user's balance after losing points
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
            if(int1 != randNum1 && int2 != randNum2 && userPoints >= 0){
            cout << "You guessed incorrectly, you lose 5 points." << endl;
            userPoints -= 5; //subtracts user's points by 5
            if(userPoints < 0){ //if points are less than 0
            cout << endl << "Your total points balance: " << userPoints << endl;
            cout << "You have run out of points." << endl;
            cout << "Goodbye " << userName << "!" << endl;
            userChoice = true; //will end loop
            break;
            }else
            cout << "Your total points balance: " << userPoints << endl << endl; //displays balance after losing points
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
        
        userPoints -= 1; //doing this subtracts user's points by 1

        cout << "Game reset." << endl;
        cout << "Your point balance: " << userPoints << endl; //shows balance after subtracted by 1
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
        cout << "Your final points balance: " << userPoints << endl;
        userChoice = true;
        break; //ends game
        default: //if user doesn't choose 1,2,3,4, or 5
            cout << "Error, invalid choice. Choose 1, 2, 3, 4, or 5: ";
            break;
        }

        }while(userChoice == false); //if it is false the loop will continue

    }while(userChoice == true); //if it is true the loop will end
    }




    return 0;
}