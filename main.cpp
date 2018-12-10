#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Cleaner.h"

using namespace std;

void showError(string const description) {
    cerr << "\033[1;31m" << description << "\033[0m" << endl;
    cerr << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        showError("ERROR: No arguments given.");
        return -1;
    }

    /*
        Retreive argument list
    */
    string fileName{};
    string outputFormat{};
    int charLimit{};

    try {
        fileName = argv[1];
        outputFormat = argv[2];

        if ((outputFormat == "-o") && (argc = 4)) {
            charLimit = stoi(argv[3]);
        } else {
            showError("ERROR: Second argument missing or invalid.");
            return -1;
        }
    } catch (const std::exception& e) {
        showError("ERROR: Incorrect argument list.");
        return -1;
    }

    /*
        Open file and pipe to cleaner
    */
    ifstream fileStream{};
    fileStream.open(fileName);
    if (!fileStream.is_open()) {
        showError("ERROR: Could not open the file.");
        return -1;
    }

    Cleaner cleaner{};
    string potentialWord{};

    while (fileStream >> potentialWord) {
        cleaner.addWord(potentialWord);
    }

    fileStream.close();

    /*
        Select output format
    */
    int maxWidth{cleaner.getLargestWordSize()};

    switch (outputFormat[1]) {
        case 'a':
            auto comparator = [](pair<string, int> left, pair<string, int> right) {
                return left.second >= right.second;
            };
            auto printer = [maxWidth](pair<string, int> currentPair) {
                cout << left << setw(maxWidth) << currentPair.first << " " << currentPair.second << endl;
            };
            cleaner.sort(comparator);
            cleaner.print(printer);
            break;

        case 'f':

            break;

        case 'o':

            break;

        default:
            showError("ERROR: Incorrect argument list.");
            return -1;
            break;
    }
}