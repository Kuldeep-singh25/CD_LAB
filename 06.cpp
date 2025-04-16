#include <iostream>
#include <typeinfo>
using namespace std;
int main() {
    // Declare some variables
    int a = 10;
    double b = 3.14;
    string c = "Hello, World!";
    char d = 'A';
    bool e = true;


    
    // Print the types of the variable
    cout << "Variable 'a' is of type: " << typeid(a).name() << endl;
    cout << "Variable 'b' is of type: " << typeid(b).name() << endl;
    cout << "Variable 'c' is of type: " << typeid(c).name() << endl;
    cout << "Variable 'e' is of type: " << typeid(e).name() << endl;
    cout << "Variable 'd' is of type: " << typeid(d).name() << endl;

    return 0;
}
