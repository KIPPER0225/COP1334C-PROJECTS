/*
    Kaden Ip

    courseSummary.cpp

    Write a menu-driven interface program that provides the user with two options:
    1. Process Grades Summary report.
    2. Quit.

    Input: User choice for menu option

    Processing 1. Display menu
               2. Prompt user for choice
               3. Drive menu options:
                Case 1 - Process Grades Summary report
                    Open "COP1334.txt" for output
                    Read and display:
                    Highest grade
                    Lowest grade
                    Average grade
                    Close file
                Case 2 - Quit
                    Display "Good Bye"

    Output: "COP1334C.txt" file containing students' grades
            List highest, lowest, & average grade.
*/

// Header Files
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <string>

int main()
{
    // Variable 
    int choice;

    // Display name of program
    cout << "Course Summary App ...\n" << endl;

    do
    {
        // Display menu & Prompt user for menu choice
        cout << "Choose one of the following options" << endl;
        cout << "     1. Process Grades Summary report." << endl;
        cout << "     2. Quit." << endl;
        cout << "Option: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // User input is 1
        {
            // Choice 1 variables
            string fileName;
            string courseName, prof, term;
            string studentName;
            int grade;

            ifstream inputFile;

            // Initialized choice 1 variables
            int highestGrade = 0;
            int lowestGrade = 100;
            int totalGrades = 0;
            int studentCount = 0;

            // Prompt user for filename
            cout << "\nGrades Summary Report ...";


            cout << "\nEnter name of file: ";
            cin >> fileName;

            // Open file
            inputFile.open(fileName);

            if (!inputFile) // Display error if file cannot be opened
            {
                cout << "\nError ... Cannot open " << fileName << "\n" << endl;
                break;
            }

            // Read course information
            getline(inputFile, courseName);
            getline(inputFile, prof);
            getline(inputFile, term);

            // Display course info
            cout << "\n--------------------------------------------------" << endl;
            cout << courseName << endl;
            cout << "\n" << left << setw(30) << prof
                << "Term: " << term << endl;

            cout << "\n\nList of Students\n";
            cout << "\n--------------------------------------------------\n";

            // Read student names and grades
            while (getline(inputFile, studentName) && inputFile >> grade)
            {
                cout << left << setw(30) << studentName
                    << grade << endl;

                if (grade > highestGrade)
                    highestGrade = grade;

                if (grade < lowestGrade)
                    lowestGrade = grade;

                totalGrades += grade;
                studentCount++;

                inputFile.ignore();
            }

            // Calculate and display highest, lowest, and average grade
            if (studentCount > 0)
            {
                double average = totalGrades * 1.0 / studentCount; // Mutiply by 1.0 to turn totalGrades into double

                cout << "\nHighest Grade: " << highestGrade << endl;
                cout << "\nLowest Grade: " << lowestGrade << endl;

                cout << fixed << setprecision(1);
                cout << "\nAverage Grade: " << average << endl;
            }
            else
            {
                cout << "\nNo student grades found." << endl;
            }

            cout << "\n--------------------------------------------------\n";

            inputFile.close();

            break;
        }
        case 2: // Display farewell
        {
            cout << "\nGood Bye ..." << endl;
            break;
        }

        default:
        {
            cout << "\nError ... Incorrect option. Try again.\n" << endl;
            break;
        }
        }
    } while (choice != 2);

    return 0;
}