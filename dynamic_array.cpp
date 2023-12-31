#include <iostream>
#include <fstream>
#include <sstream>
#include "dynamic_array.hpp"
using namespace std;

bool parseCovideFile(CovidCase *&cases, int &arraySize, int &arrayCapacity, int &doubledCounter) {

    // variable declaration
    CovidCase tempCase;
    string line;
    string lineArr[4];
    string tempString;
    string tempName;
    string tempLocation;
    string tempVariant;
    int tempAge;
    int a = 0;

    // open file and check that the file has been opened correctly
    ifstream inputFile;
    inputFile.open("covidCases.txt");
    if (inputFile.fail()) {
        cout << "File failed to open" << endl;
        return false;;
    }

    while(!inputFile.eof()) { // traverse through the file
        a = 0;
        getline(inputFile, line); // get a line of the file into a separate temp string (line)
        if (line != "") { // check for empy lines
            stringstream ss (line); // store the line into a stringstream variable to facilitate the process of storing the line
            while(getline (ss, tempString, ',')) { // traverse through the line storing the results in an array of strings
                lineArr[a] = tempString;
                a++;
            }
            // store the line in the form of a covidCase object
            tempCase.name = lineArr[0];
            tempCase.variant = lineArr[1];
            tempCase.location = lineArr[2];
            tempCase.age = stoi(lineArr[3]);
            
            // call the addCase function
            addCase(cases, tempCase, arraySize, arrayCapacity, doubledCounter);
        }
    }
    return true;
}

void addCase(CovidCase *&cases, CovidCase tempcase, int &arraySize, int &arrayCapacity, int &doubledCounter) {

    // check if the array size is equal to the array apacity
    if (arraySize == arrayCapacity) {
        resizeArr(cases, &arrayCapacity, doubledCounter); // call resizeArr which will double the size array
    }
    cases[arraySize] = tempcase; // add the new case to the array
    arraySize++; // increase the array size

    return;
}

void resizeArr(CovidCase *&cases, int *arrayCapacity, int &doubledCounter) {
    
    // calculate the new array size
    int newarraySize = *arrayCapacity *2;

    // create the new array with double the size
    CovidCase *newCases = new CovidCase[newarraySize];
    
    // copy the cases from the old list to the new one
    for (int i = 0; i < *arrayCapacity; i++) {
        newCases[i] = cases[i];
    }

    // free memory
    delete[] cases;

    // set the new array size
    *arrayCapacity = newarraySize;

    // point cases to the new array
    cases = newCases;
    doubledCounter++;
}

bool findCases(CovidCase &tempCase, string location, string variant, int minAge, int maxAge, int arraySize){

    // check for matches, if one found, return true
    if (tempCase.location == location && tempCase.variant == variant && tempCase.age >= minAge && tempCase.age <= maxAge) {
        return true;
    }
    return false;

}



