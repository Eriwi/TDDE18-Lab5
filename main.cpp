#include <iostream>
#include <string>

using namespace std;

void showUsage() {
    cout << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "ERROR: No arguments given." << endl;
        showUsage();
        return -1;
    }

    string fileName{};
    string outputFormat{};
    int charLimit{};

    try
    {
        fileName = argv[1];
        outputFormat = argv[2];

        if ((outputFormat == "-o") && (argc = 4)) {
            charLimit = stoi(argv[3]);
        } else {
            cout << "ERROR: Second argument missing or invalid." << endl;
            showUsage();
            return -1;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: Incorrect argument list." << endl;
        showUsage();
        return -1;
    }
    
    

}