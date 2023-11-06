#include <iostream>
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
   const int row = 5; //declaring global constants for array sizes
   const int col = 5;
   enum option {displayLeft = '1', displayRight = '2', guess = '3', reset = '4', exitGame = '5'}; //enumerated values for switch case


    //part 3
   string getName(string userName) //function for username, will return a string
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
    int genShowMatrix(int visArray[][col]) //generates displayed matrix, every value is -1
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
    int genHideMatrix(int hiddenArray[][col], int randnumArray[], int size) //generates hidden matrix
    {
        for(int i=0; i<row; i++)
        {

            for(int j=0; j<col; j++)
            {
                do{
                hiddenArray[i][j] = (rand() % 200) + 100; //loop generates numbers in between the two random numbers and stores into array
                }while(hiddenArray[i][j] < randnumArray[0] || hiddenArray[i][j] > randnumArray[1]);
            }
        }
        
        return hiddenArray[row][col]; //returns values into the hidden array
    }

    //part 6
    void showMatrix(int visArray[][col]) //displays visual matrix
    {
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                cout << visArray[i][j] << "\t";
            }
            cout << endl;
        }

        return;
    }

    //part 7
    int setdisplayLeft(int hiddenArray[][col], int visArray[][col], int randnumArray[], int size, int int1, int int2)
    {
        int1 = randnumArray[0]; //int1 is showed as the lowerbound number
            cout << "A correct guess will give you 1 point, and an incorrect guess will take 10 points away." << endl << endl;
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display left number" << endl;
            cout << "2. Display right number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Reset Game" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";

        return int1; //updates int1 in main
    }

    //part 8
    int setdisplayRight(int hiddenArray[][col], int visArray[][col], int randnumArray[], int size, int int1, int int2)
    {
        int2 = randnumArray[1]; //int2 is showed as the upperbound number
            cout << "A correct guess will give you 1 point, and an incorrect guess will take 10 points away." << endl << endl;
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display left number" << endl;
            cout << "2. Display right number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Reset Game" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";
            
        return int2; //updates int2 in main
    }

    //part 9
    int eliminate(int hiddenArray[][col], int visArray[][col], int rowIndex, int colIndex) //for changing -1 values in visual display to 0
    {
        for(int i=0; i<row; ++i)
        {

            
            for(int j=0; j<col; ++j)
            {
                if(rowIndex == i)
                {
                    hiddenArray[i][j] = 0;
                    visArray[i][j] = 0;
                }
                if(colIndex == j)
                {
                    hiddenArray[i][j] = 0;
                    visArray[i][j] = 0;
                }
            }
        }

        return visArray[row][col];
    }

    //part 10
    bool allZeros(int visArray[][col], bool isZero) //checks if the visual array values are all 0
    {
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(visArray[i][j] == -1)
                {
                    isZero = false;
                    break;
                }
                if(visArray[i][j] == 0)
                {
                    isZero = true;
                }
            }
        }
        return isZero; //returns the bool value
    }

    //part 11
    int funcGuess(int userGuess, int hiddenArray[][col], int visArray[][col], int userPoints, int rowIndex, int colIndex, int int1, int int2, int randnumArray[]) //for the user's guess
    {

        showMatrix(visArray); //displays visual matrix

        int correctGuess = 0;
        cout << "Enter a guess: ";
        cin >> userGuess;

        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(userGuess == hiddenArray[i][j]) //if the correct guess is one of the random numbers in between bounds
                {
                    correctGuess = hiddenArray[i][j]; 
                    rowIndex = i; //index is used for changing values to 0
                    colIndex = j;
                }
            }
        }
        if(userGuess == correctGuess) //if the user's guess is correct
        {
            if(int1 == randnumArray[0] || int2 == randnumArray[1]) //if user has showed one of the bounds
            {
                cout << "You guessed correctly, you get 1 point!" << endl;
                userPoints += 1;
            }
            if(int1 != randnumArray[0] && int2 != randnumArray[1]) //if user hasn't showed one of the bounds
            {
                cout << "You guessed correctly, you get 5 points!" << endl;
                userPoints += 5;
            }

            visArray[row][col] = eliminate(hiddenArray, visArray, rowIndex, colIndex); //calls eliminate function into visArray

            showMatrix(visArray); //displays visArray

            cout << endl;

            cout << "Your total points balance: " << userPoints << endl << endl;
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display left number" << endl;
            cout << "2. Display right number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Reset Game" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";
        }
        if(userGuess != correctGuess && userPoints >= 0) //if user guesses incorrectly
        {
            if(int1 == randnumArray[0] || int2 == randnumArray[1] && userPoints >= 0)
            {
                cout << "You guessed incorrectly, you lose 10 points." << endl;
                userPoints -= 10;
                
                if(userPoints >= 0)
                {
                cout << "Your total points balance: " << userPoints << endl << endl;
                cout << int1 << "\t" << int2 << endl << endl;
                cout << "1. Display left number" << endl;
                cout << "2. Display right number" << endl;
                cout << "3. Guess a number in between" << endl;
                cout << "4. Reset Game" << endl;
                cout << "5. Exit" << endl;
                cout << "What is your option?: ";
                }
            }
            if(int1 != randnumArray[0] && int2 != randnumArray[1] && userPoints >= 0)
            {
                cout << "You guessed incorrectly, you lose 5 points." << endl;
                userPoints -= 5;

                if(userPoints >= 0)
                {
                cout << "Your total points balance: " << userPoints << endl << endl;
                cout << int1 << "\t" << int2 << endl << endl;
                cout << "1. Display left number" << endl;
                cout << "2. Display right number" << endl;
                cout << "3. Guess a number in between" << endl;
                cout << "4. Reset Game" << endl;
                cout << "5. Exit" << endl;
                cout << "What is your option?: ";
                }
            }
        }

        return userPoints; //updates points to main
    }

    //part 12
    int initialize(int randnumArray[], int visArray[][col], int hiddenArray[][col], int size) //initializes the game
    {

        srand(time(NULL));
        randnumArray[0] = (rand() % 100) + 100;  //generates the random numbers
        randnumArray[1] = (rand() % 100) + 200;
        visArray[row][col] = genShowMatrix(visArray); //calls genShowMatrix into visArray

        hiddenArray[row][col] = genHideMatrix(hiddenArray, randnumArray, size); //calls genHideMatrix into hiddenArray

        return randnumArray[size]; //returns lower and upper bounds into main
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
    const int size = 3; //declaring variables
    bool isZero;
    int rowIndex;
    int colIndex;
    int randnumArray[size];
    int visArray[row][col];
    int hiddenArray[row][col];
    srand(time(NULL));

    randnumArray[size] = initialize(randnumArray, visArray, hiddenArray, size); //calling the initialize function to start the game

    //part 16
    string userName;
    userName = getName(userName); //calls getName function to put userName into the string

    //part 17
    
    if(userPoints >= 0){
    cout << int1 << "\t" << int2 << endl << endl; //\t puts space between int1 and 2
    cout << "1. Display left number" << endl;
    cout << "2. Display right number" << endl;
    cout << "3. Guess a number in between" << endl;
    cout << "4. Reset Game" << endl;
    cout << "5. Exit" << endl << endl;
    cout << "What is your option?: ";
    }

    //part 19
    bool userChoice = true;
    int userGuess;

    if(userPoints >= 0){ //if user's points is less than 0, the game will end
    do{

    int choice;
    cin >> choice;
    
    //part 18
    switch(choice) {
        case 1:
        
        userChoice = true;
        
        if(int2 == randnumArray[1]){ //this is if int1 has already been equaled to randNum1
            cout << "Error, you can only display one number at a time. Try again: " << endl << endl;
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display left number" << endl;
            cout << "2. Display right number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Reset Game" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";
            break;
        }

        if (userChoice != false){ //if user choice does not equal false
        
        int1 = setdisplayLeft(hiddenArray, visArray, randnumArray, size, int1, int2); //calls function to display lower bound
        break;

        }
        break;
        
        case 2:
        
        userChoice = true;

        if(int1 == randnumArray[0]){ //this is if int1 has already been equaled to randNum1
            cout << "Error, you can only display one number at a time. Try again: " << endl << endl;
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display left number" << endl;
            cout << "2. Display right number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Reset Game" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";
            break;
        }

        if (userChoice != false){ //does not equal false
        
        int2 = setdisplayRight(hiddenArray, visArray, randnumArray, size,  int1, int2); //calls function to display upperbound
        break;
        
        }
        
        break;
        

        case 3:

        if(userPoints >= 0){
        userPoints = funcGuess(userGuess, hiddenArray, visArray, userPoints, rowIndex, colIndex, int1, int2, randnumArray); //calls guess function then will update userPoints

        if(userPoints < 0){ //ends the game if user points are less than 0
                cout << endl << "Your total points balance: " << userPoints << endl;
                cout << "You have run out of points." << endl;
                cout << "Goodbye " << userName << "!" << endl;
                userChoice = false; //ends game
                break;
            }
        
        isZero = allZeros(visArray, isZero);

        if(isZero == true)
        {
            char choice2;
            cout << "Do you want to play another game? Y/N: ";
            cin >> choice2;
            if(choice2 == 'Y' || choice2 == 'y')
            {
                randnumArray[size] = initialize(randnumArray, visArray, hiddenArray, size); //restarts game
            }
            if(choice2 == 'N' || choice2 == 'n')
            {
                userChoice = false;  //ends game
                break;
            }
        }
        }

        break;

        case 4:
        
        userPoints -= 1; //doing this subtracts user's points by 1

        cout << "Game reset." << endl;

            if(userPoints < 0){ //ends the game if user points are less than 0
                cout << endl << "Your total points balance: " << userPoints << endl;
                cout << "You have run out of points." << endl;
                cout << "Goodbye " << userName << "!" << endl;
                userChoice = false;
                break;
            }

        cout << "Your point balance: " << userPoints << endl; //shows balance after subtracted by 1
        
        randnumArray[size] = initialize(randnumArray, visArray, hiddenArray, size); //restarts game
        int1 = -1;
        int2 = -1;
        
        cout << int1 << "\t" << int2 << endl << endl;
        cout << "1. Display left number" << endl;
        cout << "2. Display right number" << endl;
        cout << "3. Guess a number in between" << endl;
        cout << "4. Reset Game" << endl;
        cout << "5. Exit" << endl;
        cout << "What is your option?: ";
        
        break;
        
        case 5:
        cout << "Goodbye " << userName << "!" << endl;
        cout << "Your final points balance: " << userPoints << endl;
        userChoice = false; //ends game
        break;
        
        default: //if user doesn't choose 1,2,3,4, or 5
            cout << "Error, invalid choice. Choose 1, 2, 3, 4, or 5: ";
            break;
        }

    }while(userChoice == true); //if it is true the loop will end
    }
    

    return 0;
}