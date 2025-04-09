#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent each symbol's information
struct Symbol {
    string symbol;      // Name of the symbol
    string data_type;   // Data type of the symbol (int, float, etc.)
    string value;       // Value of the symbol (e.g., "10", "20.5")
    string scope;       // Scope of the symbol (Global/Local)
};

class SymbolTable {
private:
    vector<Symbol> table;  // Vector to store symbols dynamically

public:
    // Method to insert a symbol into the table
    void insert(const string& symbol, const string& data_type, const string& scope, const string& value = "") {
        Symbol new_symbol = {symbol, data_type, value, scope};
        table.push_back(new_symbol);  // Add the new symbol to the vector
    }

    // Method to display the content of the symbol table
    void display() {
        if (table.empty()) {
            cout << "Symbol Table is empty." << endl;
            return;
        }

        // Displaying the header without setw
        cout << "Symbol          Data Type      Value          Scope" << endl;
        cout << "------------------------------------------------------" << endl;

        // Loop through each symbol and display its details
        for (int i = 0; i < table.size(); i++) {
            cout << table[i].symbol << "          "
                 << table[i].data_type << "      "
                 << table[i].value << "          "
                 << table[i].scope << endl;
        }
    }
};

int main() {
    SymbolTable symbolTable;

    // Inserting symbols into the table with scope information
    symbolTable.insert("x", "int", "Global", "10");
    symbolTable.insert("y", "float", "Global", "20.5");
    symbolTable.insert("name", "string", "Local", "\"Alice\"");
    symbolTable.insert("is_active", "bool", "Local", "true");

    // Displaying the symbol table
    symbolTable.display();

    return 0;
}
