#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to evaluate the expression
int evaluate(const string& expr) {
    int result = 0, currentNumber = 0;
    char lastOperator = '+';

    for (int i = 0; i < expr.size(); ++i) {
        char ch = expr[i];

        if (isdigit(ch)) {
            currentNumber = currentNumber * 10 + (ch - '0');
        }

        if ((!isdigit(ch) && ch != ' ') || i == expr.size() - 1) {
            if (lastOperator == '+') result += currentNumber;
            else if (lastOperator == '-') result -= currentNumber;
            else if (lastOperator == '*') result *= currentNumber;
            else if (lastOperator == '/') result /= currentNumber;

            currentNumber = 0;
            lastOperator = ch;
        }
    }
    return result;
}

int main() {
    string expression;
    cout << "Enter an arithmetic expression: ";
    getline(cin, expression);
    if(evaluate(expression)==0){
        cout << "Result: TRUE "  << endl;}
        else cout << "Result: FALSE "  << endl;
    return 0;
}
