/* 
    Include needed dependencies for running program
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

/* 
    Global instantiation of std
*/
using namespace std;

/* 
    Main function for data processing
*/
int main() {

    // Input file variable
    ifstream inFile;

    // File open
    inFile.open("inputText.txt");

    // Error handling
    if(!inFile.is_open()) {
        cout << "Could not open the file inputText.txt" << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    };

    // String variable for data output
    string line;

    // If successful that file opens
    if(inFile.is_open()) {

        // Get the line of data from file
        while (getline(inFile, line)) {

            // Print the data
            cout << line << endl;
        };
    }

    // If at the end of file close
    if (inFile.eof()) {
        inFile.close();
    } 

    // Error handling
    else if (inFile.fail()) {
        cout << "Input terminated by data mismatch.\n";
    } else {
        cout << "Input terminated for unknown reason.\n";
    }

    // Close file
    inFile.close();

    // Return int value
    return 0;
}