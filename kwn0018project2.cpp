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
   const int row = 5;
   const int col = 5;
   //const int size = 2;
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
    int genHideMatrix(int hiddenArray[][col], int randnumArray[], int size)
    {
        for(int i=0; i<row; i++)
        {

            for(int j=0; j<col; j++)
            {
                do{
                hiddenArray[i][j] = (rand() % 200) + 100;
                }while(hiddenArray[i][j] < randnumArray[0] || hiddenArray[i][j] > randnumArray[1]);
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
                cout << visArray[i][j] << "\t";
            }
            cout << endl;
        }

        return;
    }

    //part 7
    int setdisplayLeft(int hiddenArray[][col], int visArray[][col], int randnumArray[], int size, int int1, int int2)
    {
        int1 = randnumArray[0];
            cout << "A correct guess will give you 1 point, and an incorrect guess will take 10 points away." << endl << endl;
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display left number" << endl;
            cout << "2. Display right number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Reset Game" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";

        return int1;
    }

    //part 8
    int setdisplayRight(int hiddenArray[][col], int visArray[][col], int randnumArray[], int size, int int1, int int2)
    {
        int2 = randnumArray[1];
            cout << "A correct guess will give you 1 point, and an incorrect guess will take 10 points away." << endl << endl;
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display left number" << endl;
            cout << "2. Display right number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Reset Game" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";
            
        return int2;
    }

    //part 9
    int eliminate(int hiddenArray[][col], int visArray[][col], int rowIndex, int colIndex)
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
    bool allZeros(int visArray[][col], bool isZero)
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
        return isZero;
    }

    //part 11
    int funcGuess(int userGuess, int hiddenArray[][col], int visArray[][col], int userPoints, int rowIndex, int colIndex, int int1, int int2, int randnumArray[])
    {

        showMatrix(visArray);

        int correctGuess = 0;
        cout << "Enter a guess: ";
        cin >> userGuess;

        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(userGuess == hiddenArray[i][j])
                {
                    correctGuess = hiddenArray[i][j];
                    rowIndex = i;
                    colIndex = j;
                }
            }
        }
        if(userGuess == correctGuess)
        {
            if(int1 == randnumArray[0] || int2 == randnumArray[1])
            {
                cout << "You guessed correctly, you get 1 point!" << endl;
                userPoints += 1;
            }
            if(int1 != randnumArray[0] && int2 != randnumArray[1])
            {
                cout << "You guessed correctly, you get 5 points!" << endl;
                userPoints += 5;
            }

            visArray[row][col] = eliminate(hiddenArray, visArray, rowIndex, colIndex);

            showMatrix(visArray);

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
        if(userGuess != correctGuess && userPoints >= 0)
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

        return userPoints;
    }

    //part 12
    int initialize(int randnumArray[], int visArray[][col], int hiddenArray[][col], int size)
    {

        srand(time(NULL));
        randnumArray[0] = (rand() % 100) + 100;  //generates the random numbers
        randnumArray[1] = (rand() % 100) + 200;
        visArray[row][col] = genShowMatrix(visArray);

        hiddenArray[row][col] = genHideMatrix(hiddenArray, randnumArray, size);

        return randnumArray[size];
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
    const int size = 2;
    bool isZero;
    int rowIndex;
    int colIndex;
    int randnumArray[size];
    int visArray[row][col];
    int hiddenArray[row][col];
    srand(time(NULL));

    randnumArray[size] = initialize(randnumArray, visArray, hiddenArray, size);

    //part 16
    string userName = getName(userName);

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

        if(userPoints < 0){ //ends the game if user points are less than 0
                cout << endl << "Your total points balance: " << userPoints << endl;
                cout << "You have run out of points." << endl;
                cout << "Goodbye " << userName << "!" << endl;
                userChoice = true;
                break;
            }

        //do{

    
    int choice;
    cin >> choice;
    
    //part 18
    switch(choice) {
        case 1:
        
        //userChoice = true;
        
        if(int2 == randnumArray[1]){ //this is if int1 has already been equaled to randNum1
            cout << "Error, you can only display one number at a time. Try again: " << endl << endl;
            userChoice = false;
        }
        if(userChoice == false){ //asks user to decide again
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display left number" << endl;
            cout << "2. Display right number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Reset Game" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";
            break;
            cin >> choice;
        }

        else if (userChoice != false){ //if user choice does not equal false
        
        int1 = setdisplayLeft(hiddenArray, visArray, randnumArray, size, int1, int2);
        break;
        //cin >> choice;

        }
        break;
        
        case 2:
        
        userChoice = true;

        if(int1 == randnumArray[0]){ //if option 1 has already been chosen
            cout << "Error, you can only display one number at a time. Try again: " << endl << endl;
            userChoice = false;
        }
        if(userChoice == false){ //will make user choose again
            cout << int1 << "\t" << int2 << endl << endl;
            cout << "1. Display left number" << endl;
            cout << "2. Display right number" << endl;
            cout << "3. Guess a number in between" << endl;
            cout << "4. Reset Game" << endl;
            cout << "5. Exit" << endl;
            cout << "What is your option?: ";
            break;
            cin >> choice;
        }

        else if (userChoice != false){ //does not equal false
        
        int2 = setdisplayRight(hiddenArray, visArray, randnumArray, size,  int1, int2);
        break;
        //cin >> choice;
        
        }
        
        break;
        

        case 3:

        if(userPoints >= 0){
        userPoints = funcGuess(userGuess, hiddenArray, visArray, userPoints, rowIndex, colIndex, int1, int2, randnumArray);
        
        isZero = allZeros(visArray, isZero);

        if(isZero == true)
        {
            char choice2;
            cout << "Do you want to play another game? Y/N: ";
            cin >> choice2;
            if(choice2 == 'Y' || choice2 == 'y')
            {
                randnumArray[size] = initialize(randnumArray, visArray, hiddenArray, size);
            }
            if(choice2 == 'N' || choice2 == 'n')
            {
                break;
            }
        }
        }
        //userChoice = true;
        break;

        case 4:
        
        userPoints -= 1; //doing this subtracts user's points by 1

        cout << "Game reset." << endl;
        cout << "Your point balance: " << userPoints << endl; //shows balance after subtracted by 1
        
        randnumArray[size] = initialize(randnumArray, visArray, hiddenArray, size);
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
        userChoice = true;
        break; //ends game
        
        default: //if user doesn't choose 1,2,3,4, or 5
            cout << "Error, invalid choice. Choose 1, 2, 3, 4, or 5: ";
            break;
        }

        //}while(userChoice == false); //if it is false the loop will continue

    }while(userChoice == true); //if it is true the loop will end
    }

    return 0;
}