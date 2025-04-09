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
    cout << "Variable 'a' is of type: " << typeid(a).name() << std::endl;
    cout << "Variable 'b' is of type: " << typeid(b).name() << std::endl;
    cout << "Variable 'c' is of type: " << typeid(c).name() << std::endl;
    cout << "Variable 'e' is of type: " << typeid(e).name() << std::endl;
    cout << "Variable 'd' is of type: " << typeid(d).name() << std::endl;

    return 0;
}
