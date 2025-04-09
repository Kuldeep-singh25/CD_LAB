//Lab-4 Write a program that will create and display content of Symbol table.
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to represent each symbol's information
struct Symbol {
    string symbol;
    string data_type;
    string value;
};

class SymbolTable {
private:
    vector<Symbol> table;  // Vector to store symbols dynamically

public:
    // Method to insert a symbol into the table
    void insert(const string& symbol, const string& data_type, const string& value = "") {
        Symbol new_symbol = {symbol, data_type, value};
        table.push_back(new_symbol);  // Add the new symbol to the vector
    }

    // Method to display the content of the symbol table
    void display() {
        if (table.empty()) {
            cout << "Symbol Table is empty." << endl;
            return;
        }

        // Displaying the header
        cout << left << setw(15) << "Symbol" 
             << setw(15) << "Data Type" 
             << setw(20) << "Value" << endl;
        cout << string(50, '-') << endl;

        // Loop through each symbol and display its details
        for (const auto& entry : table) {
            cout << left << setw(15) << entry.symbol
                 << setw(15) << entry.data_type
                 << setw(20) << entry.value << endl;
        }
    }
};

int main() {
    SymbolTable symbolTable;

    // Inserting symbols into the table
    symbolTable.insert("x", "int", "10");
    symbolTable.insert("y", "float", "20.5");
    symbolTable.insert("name", "string", "\"Alice\"");
    symbolTable.insert("is_active", "bool", "true");

    // Displaying the symbol table
    symbolTable.display();

    return 0;
}
