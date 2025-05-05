#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>
#include <cxxabi.h>

using namespace std;

// Function to demangle type names
string demangle(const char* mangledName) {
    int status = 0;
    char* demangled = abi::__cxa_demangle(mangledName, nullptr, nullptr, &status);
    string result = (status == 0 && demangled != nullptr) ? demangled : mangledName;
    free(demangled);
    return result;
}

// Symbol structure
struct Symbol {
    string name;
    string value;
    string type;
    void* address;
    string scope;
};

// Helper to create a symbol entry
template<typename T>
Symbol createSymbol(const string& name, T& var, const string& scope) {
    Symbol sym;
    sym.name = name;
    sym.value = to_string(var);  // for int, float, double
    sym.type = demangle(typeid(var).name());
    sym.address = static_cast<void*>(&var);
    sym.scope = scope;
    return sym;
}

// Overload for string type (std::to_string doesn't work on string)
template<>
Symbol createSymbol<string>(const string& name, string& var, const string& scope) {
    Symbol sym;
    sym.name = name;
    sym.value = var;
    sym.type = demangle(typeid(var).name());
    sym.address = static_cast<void*>(&var);
    sym.scope = scope;
    return sym;
}

// Global variable
int globalVar = 100;

int main() {
    // Local variables
    int intVar = 10;
    float floatVar = 3.14f;
    double doubleVar = 9.81;
    string strVar = "Hello";

    // Create symbol table
    Symbol symbols[] = {
        createSymbol("globalVar", globalVar, "global"),
        createSymbol("intVar", intVar, "local"),
        createSymbol("floatVar", floatVar, "local"),
        createSymbol("doubleVar", doubleVar, "local"),
        createSymbol("strVar", strVar, "local")
    };

    // Print the symbol table
    cout << left
         << setw(15) << "Variable"
         << setw(15) << "Value"
         << setw(20) << "Type"
         << setw(20) << "Address"
         << setw(10) << "Scope" << endl;

    cout << string(80, '-') << endl;

    for (const auto& sym : symbols) {
        cout << setw(15) << sym.name
             << setw(15) << sym.value
             << setw(20) << sym.type
             << setw(20) << sym.address
             << setw(10) << sym.scope << endl;
    }

    return 0;
}