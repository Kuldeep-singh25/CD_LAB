#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cerr << "Could not open the file " << filename << endl;
        return 1;
    }

    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;
    string line;

    while (getline(file, line)) {
        lineCount++;
        charCount += line.length(); // +1 for newline character
        istringstream iss(line);
        string word;
        while (iss >> word) {
            wordCount++;
        }
    }

    file.close();

    cout << "Characters: " << charCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Lines: " << lineCount << endl;

    return 0;
}