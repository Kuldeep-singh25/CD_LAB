#include <iostream>
#include <string>
using namespace std;

//  if( condition )
bool check_if_format(string input)
{
     int length = input.length();
     if (length >= 4 && input.substr(0, 2) == "if" && input[2] == '(' && input[length - 1] == ')')
     { return true;}
     return false;
}

// Condition
bool check_condition_validity(string input)
{
     bool operator_found = false;
     bool operand_found = false;
     for (int i = 4; input[i] != ')'; i++)
     {
          if (input[i] == ' ')
               continue;
          if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') ||
           (input[i] >= '0' && input[i] <= '9'))
          { operand_found = true; }
          else if (input[i] == '>' || input[i] == '<' || (input[i] == '=' && input[i + 1] == '=') ||
           (input[i] == '!' && input[i + 1] == '=')) // only simple condition
          {operator_found = true;
               if (input[i] == '=' || input[i] == '!')
               {
                    i++;
               } }
          else return false;
     }
     return operator_found && operand_found;
}

int main()
{
     char input[50];
     cout << "Enter your if statement (e.g., if(x > 10) and don't use () in condition):" << endl;
     cin.getline(input, 50);
     if (!check_if_format(input))
     {cout << "Error: The 'if' statement format is incorrect. It should be in the form 'if( condition )'." << endl;
          return 0;}

     if (!check_condition_validity(input))
     {cout << "Error: The condition inside the 'if' statement is invalid." << endl;}
     else
     {cout << "The 'if' statement has a valid condition." << endl;}

     return 0;
}