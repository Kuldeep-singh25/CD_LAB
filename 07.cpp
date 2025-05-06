#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Symbol {
    string name;
    string type;
    string scope; 
};

int main() {
    vector<Symbol> table;
    string inp;
    bool isLocal = false;

    cout << "Enter code input (type \"END\" at last to stop):\n";
    while (getline(cin, inp)) {
        if (inp == "END") break;

        if (inp == "{") {
            isLocal = true;
        } else if (inp == "}") {
            isLocal = false;
        } else {
            size_t space = inp.find(' ');
            size_t semi = inp.find(';');

            if (space != string::npos && semi != string::npos) {
                string type = inp.substr(0, space);
                string name = inp.substr(space + 1, semi - space - 1);
                string scope = isLocal ? "local" : "global";
                table.push_back({name, type, scope});
            }
        }
    }
    cout << "\n--- Symbol Table ---\n";
    for (auto& sym : table) {
        cout << "Name: " << sym.name << ", Type: " << sym.type << ", Scope: " << sym.scope << endl;
    }
}