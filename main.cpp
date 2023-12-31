#include <iostream>
#include "dynamic_array.hpp"
using namespace std;


int main() {

    // variable declaration
    bool firstMatch = true;
    int doubledCounter = 0;
    int arraySize = 0; // number of objects alocated into the array
    int arrayCapacity = 10; // capacity of the array
    bool parseResult = true;
    bool searchResult = false;
    char userInput;
    string userLocation;
    string userVariant;
    int userMaxAge = 0;
    int userMinAge = 0;
    CovidCase *covidCases = new CovidCase[arrayCapacity]; // the array that contains all the covid cases, with an initial size of 10
    CovidCase tempCase;

    // here we wanna call parseCovideFile
    parseResult = parseCovideFile(covidCases, arraySize, arrayCapacity, doubledCounter);
    if (parseResult == false) {
        return -1;
    }

    cout << "The array was created successfully" << endl;
    cout << endl;
    cout << "The total registered cases sums up to: " << arraySize << " cases" << endl;
    cout << "The final array capacity is: " << arrayCapacity << endl;
    cout << "To achieve this it had to be doubled " << doubledCounter << " times." << endl;
    cout << endl;
    cout << "If you want to search for any case in specific please let me know. Otherwise I'll end the program (y/n)" << endl;
    spot1:
    cin>> userInput;

    if (userInput == 'y') {

        // ask for user input
        cout << "Great, you will be able to find cases by introducing location, variant and age range: " << endl;
        
        cout << "Location: ";
        cin>> userLocation;
        cout << endl;

        cout << "Variant: ";
        cin>> userVariant;
        cout << endl;

        cout << "Min age: ";
        cin >> userMinAge;
        cout << endl;

        cout << "Max age: ";
        cin>> userMaxAge;
        cout << endl;


        // traverse the created list searching for any matches
        for (int i = 0; i < arraySize; i++) {
            tempCase = covidCases[i];
            searchResult = findCases(tempCase, userLocation, userVariant, userMinAge, userMaxAge, arraySize);
            if (searchResult == true) { // if we have found a mathc
                if (firstMatch == true) { // if it's the first match then print this kind of "header"
                    cout << "These are the matches with the information you have provided:" << endl << endl;
                    firstMatch = false;
                }
                cout << tempCase.name << ", " << tempCase.variant << ", " << tempCase.location << ", " << tempCase.age << endl; // print the found case
            }
        }
        if (firstMatch == true) { // if there are no matches
            cout << "Sorry but we don't have any matches in our system with the information you have provided." << endl;
        }

    } else if (userInput == 'n') {
        return 1;
    } else {
        cout << "Please respond with y/n." << endl;
        goto spot1;
    }

    return 1;
}