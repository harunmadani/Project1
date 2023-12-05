/* Group mates:
    Keller Neu kwn0018 kellerneu@my.unt.edu
    Jose Rubio jcr0377 joserubio2@my.unt.edu
    Jose Fraire jjf0140 josefraire@my.unt.edu
    Aaron Madani hs0711 AaronMadini@my.unt.edu
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

//part 1
const int testSize = 5;

enum option {Add = '1', Remove = '2', Display = '3', Search = '4', Results = '5', Quit = '6'};

struct Student
{
    string stuName;
    string stuID;
    int testsTaken;
    int *testScore;
    double scoreAvg;
};

int getNumber()
{
    ifstream fin;
    fin.open("student.dat");

    if(fin.fail())
    {
        cout << "Error opening file." << endl;
        exit(1);
    }

    int count = 0;
    string line;

    while(!fin.eof())
    {
        getline(fin, line);
        ++count;
    }

    fin.close();

    return(count);
}

//part 3
void add_student() {

    ofstream outFS;
    Student add;

    string temp;
    getline(cin, temp);

    cout << "Enter last name of the student: ";
    getline(cin, add.stuName);

    cout << "Enter first name of the student: ";
    getline(cin, temp);

    add.stuName += ',' +temp;

    cout << "Enter student ID: ";
    cin >> add.stuID;

    cout << "How many tests did this student take?: ";
    cin >> add.testsTaken;

    add.testScore = new int[add.testsTaken];

    for (int i=0; i<add.testsTaken; i++)
    {
        cout << "Enter score #" << i+1 << ": ";
        cin >> add.testScore[i];
    }

    outFS.open("student.dat", ios::app);
    outFS << endl;

    outFS<< add.stuName << "," << add.stuID << "," << add.testsTaken << ',';

    for(int i=0; i<add.testsTaken; i++)
    {
        outFS << add.testScore[i] << ',';
    }

    outFS.close();

    delete[] add.testScore;

}

//part 4
void remove_student(string studentID)
{

    ifstream inFS;
    int stuNum = getNumber();
    string tempString;
    Student *array;
    array = new Student[stuNum];

    inFS.open("student.dat");

    bool match = false;

    for(int i=0; i<stuNum; i++)
    {
        int testNum = 0;

        getline(inFS, array[i].stuName, ',');
        getline(inFS, tempString, ',');
        array[i].stuName = array[i].stuName + "," + tempString;
        getline(inFS, array[i].stuID, ',');

        if(array[i].stuID == studentID)
        {
            match = true;
        }

        getline(inFS, tempString, ',');

        array[i].testsTaken = stoi(tempString);

        array[i].testScore = new int[array[i].testsTaken];

        for(int j=0; j<array[i].testsTaken; j++)
        {
            getline(inFS, tempString, ',');
            array[i].testScore[j] = stoi(tempString);
        }

        getline(inFS, tempString);

    }

    inFS.close();
    ofstream outFS;

    if(match)
    {
        outFS.open("student.dat");
        for(int k=0; k<stuNum; k++)
        {
            if(array[k].stuID == studentID)
            {
                continue;
            }
            else
            {
                outFS << array[k].stuName << ',' << array[k].stuID << "," << array[k].testsTaken << ",";

                for(int i=0; i<array[k].testsTaken; i++)
                {
                    outFS << array[k].testScore[i] << ",";
                }
            }

            if(k != stuNum - 1)
            {
                outFS << endl;
            }
        }
    }
    else
    {
        cout << "Error, no match for student ID: " << studentID;
    }

    outFS.close();

    for(int k=0; k<stuNum; k++)
    {
        delete[] array[k].testScore;
    }

    delete[] array;
    
}

//part 5
void display()
{

    ifstream inFS;

    int stuNum = getNumber();
    string tempString;
    Student *array;
    array = new Student[stuNum];
    
    inFS.open("student.dat");

    for(int i=0; i<stuNum; i++)
    {
        int testNum = 0;

        getline(inFS, array[i].stuName, ',');
        getline(inFS, tempString, ',');

        array[i].stuName = array[i].stuName + "," + tempString;

        getline(inFS,array[i].stuID, ',');
        getline(inFS, tempString, ',');

        array[i].testsTaken = stoi(tempString);

        array[i].testScore = new int[array[i].testsTaken];

        for(int j=0; j<array[i].testsTaken; j++)
        {
            getline(inFS, tempString, ',');
            array[i].testScore[j] = stoi(tempString);
        }

        getline(inFS, tempString);

    }

    for(int k=0; k<stuNum; k++)
    {
        cout << setw(30) << array[k].stuName << setw(15) << array[k].stuID;

        for(int i=0; i<array[k].testsTaken; i++)
        {
            cout << setw(5) << array[k].testScore[i];
        }

        cout << endl;
    }

    for(int k=0; k<stuNum; k++)
    {
        delete[] array[k].testScore;
    }

    delete [] array;

}

//part 6
void search()
{

    ifstream inFS;
    inFS.open("student.dat");

    Student *var;

    for(int i=0; i<testSize; i++)
    {
        
    }


}

//part 7
void exportResults()
{

}

//part 8
void findMinimum()
{

}


int main() {

    //Part 2

    int choice;

    do{
    
    cout << "1. Add" << endl;
    cout << "2. Remove" << endl;
    cout << "3. Display" << endl;
    cout << "4. Search" << endl;
    cout << "5. Results" << endl;
    cout << "6. Quit" << endl;

    cout << "Enter choice: ";
    cin >> choice;

    string stuID;

    switch(choice){

        case 1:

            add_student();

            break;

        case 2:

            cout << "Enter ID of student to remove: ";
            cin >> stuID;
            
            remove_student(stuID);

            break;

        case 3:

            display();

            break;

        case 4:

            search();

            break;
        
        case 5:

            exportResults();

            break;
        
        case 6:

            cout << "Bye!" << endl;

            break;
        
        default:

            cout << "Error, invalid number." << endl;

            break;

        

    }
    }while(choice != 6);


    return 0;
}