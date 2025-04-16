#include <iostream>
#include <string>

using namespace std;

bool areCommentsValid(const string& code) {
    bool inMultiLineComment = false;

    for (size_t i = 0; i < code.length(); ++i) {
        if (!inMultiLineComment) {
            if (code[i] == '/' && i + 1 < code.length()) {
              if (code[i + 1] == '*') {
                    inMultiLineComment = true;
                    ++i;
                }
            }
        
        } else if (inMultiLineComment) {
            if (code[i] == '*' && i + 1 < code.length() && code[i + 1] == '/') {
                inMultiLineComment = false;
                ++i;
            }
        }
    }
    return !inMultiLineComment;
}

int main() {
    cout << "Enter your code (press Enter on a blank line to finish):\n";

    string line, code;
    while (true) {
        getline(cin, line);
        if (line.empty()) break; // Stop on blank line
        code += line + '\n';
    }

    if (areCommentsValid(code)) {
        cout << "Comments are valid.\n";
    } else {
        cout << "Invalid comment detected.\n";
    }

    return 0;
}
