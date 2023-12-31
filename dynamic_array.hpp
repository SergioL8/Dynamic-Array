#include <iostream>
using namespace std;


struct CovidCase {
    string name;
    string location;
    string variant;
    int age;
};



// this function reads a file, creates a CovidCase object, and updates the array containing all the covid cases
/*
    arguments{
        1. Array
        2. Size of the array (ocuppied spots in the array)
        3. Capacity of the array
    }
*/  
bool parseCovideFile(CovidCase *&cases, int &arraySize, int &arrayCapacity, int &doubledCounter);
void addCase(CovidCase *&cases, CovidCase tempcase, int &arraySize, int &arrayCapacity, int &doubledCounter);
void resizeArr(CovidCase *&cases, int *arrayCapacity, int &doubledCounter);
bool findCases(CovidCase &tempCase, string location, string variant, int minAge, int maxAge, int arraySize);

