#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to identify if a string is a keyword
bool isKeyword(const string &word) {
    return word == "int" || word == "float" || word == "double" || word == "char" ||
           word == "if" || word == "else" || word == "while" || word == "for" || word == "return";
}

// Function to check if a string is a valid identifier (variable name)
bool isIdentifier(const string &word) {
    if (isdigit(word[0])) return false; // Identifiers can't start with a digit
    for (char c : word) {
        if (!isalnum(c) && c != '_') return false;
    }
    return true;
}

// Function to check if a string is a number
bool isNumber(const string &word) {
    for (char c : word) {
        if (!isdigit(c)) return false;
    }
    return true;
}

// Function to classify and extract tokens from the code
void extractTokens(const string &code) {
    string word;
    for (char c : code) {
        if (isspace(c)) {
            if (!word.empty()) {
                // Token processing
                if (isKeyword(word)) cout << "Keyword: " << word << endl;
                else if (isIdentifier(word)) cout << "Identifier: " << word << endl;
                else if (isNumber(word)) cout << "Literal: " << word << endl;
                else cout << "Unknown: " << word << endl;
                word.clear();
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == ';' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']') {
            if (!word.empty()) {
                // Token processing for the current word before punctuation
                if (isKeyword(word)) cout << "Keyword: " << word << endl;
                else if (isIdentifier(word)) cout << "Identifier: " << word << endl;
                else if (isNumber(word)) cout << "Literal: " << word << endl;
                word.clear();
            }
            cout << "Punctuation: " << c << endl; // Handle operators and punctuation
        } else {
            word += c;  // Accumulate characters for identifiers or keywords
        }
    }

    // Process the last word if any
    if (!word.empty()) {
        if (isKeyword(word)) cout << "Keyword: " << word << endl;
        else if (isIdentifier(word)) cout << "Identifier: " << word << endl;
        else if (isNumber(word)) cout << "Literal: " << word << endl;
        else cout << "Unknown: " << word << endl;
    }
}

int main() {
    string code;
    cout << "Enter C++ code (end input with an empty line):\n";
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break; // Stop input when an empty line is encountered
        code += line + " "; // Add a space between lines
    }

    cout << "\nExtracted Tokens:\n";
    extractTokens(code);

    return 0;
}
