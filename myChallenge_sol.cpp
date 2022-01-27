/* 
    Include needed dependencies for running program
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
// added for solution
#include <regex>
#include <vector>

/* 
    Global instantiation of std
*/
using namespace std;

// solution
struct Data{
    string severity;
    int level;
    string animal;
};

/* 
    Main function for data processing
*/
int main() {
    
    vector<Data> def = {{"High", 500, "Dog"},
        {"High", 400, "Cow"},
        {"Medium", 300, "Otter"},
        {"Low", 100, "Pig"}};
    
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
        string first_part;
        string second_part;

        regex regexpone("[a-zA-z].+[|]");
        regex regexptwo("[|][a-zA-Z].+");

        smatch one;
        smatch two;

        // Get the line of data from file
        while (getline(inFile, line)) {
            first_part = regex_search(line,one,regexpone);
            second_part = regex_search(line,two,regexptwo);

            string first;
            string second;

            for (auto x: one) {
                regex removebar("[|]");
                first = regex_replace(string(x), removebar, "");
            }
            for (auto x: two) {
                regex removebar("[|]");
                second = regex_replace(string(x), removebar, "");
            }

            for (const auto &arr : def) {
                if (first == arr.animal) {
                    cout << arr.severity << " | " << arr.level << " | " << arr.animal << " | " << second << endl;
                }
            }
        };
    };

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