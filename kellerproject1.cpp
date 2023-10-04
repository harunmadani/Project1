#include <iostream>
#include <string>
#include <cmath>
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
    enum choice {displayLeft = '1', displayRight = '2', guess = '3', change = '4', exit = '5'};
    string userName;


    //part 4
    cout << "Enter your name: ";
    getline(cin, userName);
    
    //This is part 4, need to figure out how to only get letters and white spaces in the username

    //part 5
    int randNum1;
    int randNum2;

    srand(time(NULL));
    


    return 0;
}