//Lab 1-Program to recognize arithmetic expression.

import java.util.*;

public class shwet1 {
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
System.out.print("Enter an arithmetic expression: ");
String expression = sc.nextLine();
boolean isValid = true;
boolean lastOperator = true;
Stack<Character> st = new Stack<>();
for (char c : expression.toCharArray()) {
if (c == ' ') {
continue;
}
if (Character.isDigit(c) || Character.isLetter(c)) {
lastOperator = false;
} else if (c == '+' || c == '-' || c == '*' || c == '/') {
if (lastOperator) {
isValid = false;
break;
}
lastOperator = true;
} else if (c == '(') {
st.push(c);
lastOperator = true;
} else if (c == ')') {
if (st.isEmpty() || lastOperator) {
isValid = false;
break;
}
st.pop();
lastOperator = false;
} else {
isValid = false;
break;
}
}
if (lastOperator || !st.isEmpty()) {
isValid = false;
}
System.out.println("The expression is " + (isValid ? "valid." : "invalid."));
}
}
//Lab 2- Conversion of infix notation to postfix notation Program
import java.util.*;

public class Lab2 {
private static boolean isOperator(char c) {
return c == '+' || c == '-' || c == '*' || c == '/';
}
private static int precedence(char c) {
if (c == '+' || c == '-') {
return 1;
} else if (c == '*' || c == '/') {
return 2;
}
return -1;
}
public static String conversion(String infix) {
Stack<Character> stack = new Stack<>();
StringBuilder postfix = new StringBuilder();
for (int i = 0; i < infix.length(); i++) {
char c = infix.charAt(i);
if (Character.isLetterOrDigit(c)) {
postfix.append(c);
} else if (c == '(') {
stack.push(c);
} else if (c == ')') {
while (!stack.isEmpty() && stack.peek() != '(') {
postfix.append(stack.pop());
}
stack.pop();
} else if (isOperator(c)) {
while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(c)) {
postfix.append(stack.pop());
}
stack.push(c);
}
}
while (!stack.isEmpty()) {
postfix.append(stack.pop());
}
return postfix.toString();
}
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
System.out.print("Enter an infix expression: ");
String infix = sc.nextLine();
String postfix = conversion(infix);
System.out.println("Postfix expression: " + postfix);
}
}
//Lab-3 Program to Check valid If statements in C program and report errors to user.
import java.util.*;

public class shwet3 {
public static boolean isValidIf(String ifCondition) {
ifCondition = ifCondition.trim();
if (!ifCondition.startsWith("if(")) {
return false;
}
int openParenIdx = ifCondition.indexOf('(');
int closeParenIdx = ifCondition.indexOf(')');
if (openParenIdx == -1 || closeParenIdx == -1 || openParenIdx >=
closeParenIdx) {
return false;
}
String condition = ifCondition.substring(openParenIdx + 1,
closeParenIdx).trim();
return !condition.isEmpty();
}
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
System.out.print("Enter an if condition : ");
String ifCondition = sc.nextLine();
if (isValidIf(ifCondition)) {
System.out.println("Valid if condition ");
} else {
System.out.println("Invalid if condition ");
}
}
}
//Lab-4 Write a program that will create and display content of Symbol table
import java.util.*;

class Symbol {
int serialNo;
String varName;
String varType;
String scope;
public Symbol(int serialNo, String varName, String varType, String scope) {
this.serialNo = serialNo;
this.varName = varName;
this.varType = varType;
this.scope = scope;
}
public void display() {
System.out.printf("%-10d %-15s %-15s %-10s\n", serialNo, varName,
varType, scope);
}
}

public class shwet4 {
     public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          HashMap<Integer, Symbol> symboltable = new HashMap<>();
          System.out.println("Enter the number of variables");
          int n = sc.nextInt();
          sc.nextLine();
          for (int i = 1; i <= n; i++) {
               System.out.println("Enter the details of variables " + i + ":");
               System.out.println("Variable Name: ");
               String varString = sc.nextLine();
               System.out.println("Variable Type: ");
               String varType = sc.nextLine();
               System.out.println("Scope: ");
               String scope = sc.nextLine();
               symboltable.put(i, new Symbol(i, varString, varType, scope));
          }
          System.out.printf("%-10s %-15s %-10s %-10s\n", "S.No.", "Variable Name",
                    "Variable Type", " Scope");
          System.out.println("----------------------------------------------");
          for (Symbol symbol : symboltable.values()) {
               symbol.display();
          }
     }

}//Lab 5 Program to extract all tokens from code.Program

import java.util.*;
import java.util.regex.*;

public class Lab5 {
     private static final String IDENTIFIERS = "\\b[a-zA-Z_][a-zA-Z0-9_]*\\b";
     private static final String OPERATORS = "[+\\-*/%=!&|<>]+";
     private static final String LITERALS = "\\b\\d+(\\.\\d+)?\\b|\"[^\"]*\"|true|false";
     private static final String SPECIAL_SYMBOLS = "[{}();,]";

     public static void main(String[] args) {
          Scanner scanner = new Scanner(System.in);
          System.out.println("Enter Java-like code (Press Enter twice to finish input):");
          StringBuilder codeBuilder = new StringBuilder();
          String line;
          while (!(line = scanner.nextLine()).isEmpty()) {
               codeBuilder.append(line).append("\n");
          }
          String javaCode = codeBuilder.toString();
          tokenize(javaCode);
          scanner.close();
     }

     public static void tokenize(String code) {
          System.out.println("\nTokens Found:");
          System.out.printf("%-20s %-40s\n", "Token Type", "Tokens");
          System.out.println("--------------------------------------------");
          findTokens("Identifiers", IDENTIFIERS, code);
          findTokens("Operators", OPERATORS, code);
          findTokens("Literals", LITERALS, code);
          findTokens("Special Symbols", SPECIAL_SYMBOLS, code);
     }

     private static void findTokens(String tokenType, String patternStr, String code) {
          Pattern pattern = Pattern.compile(patternStr);
          Matcher matcher = pattern.matcher(code);
          StringBuilder tokens = new StringBuilder();
          while (matcher.find()) {
               tokens.append(matcher.group()).append(", ");
          }
          if (tokens.length() > 0) {
               tokens.setLength(tokens.length() - 2);
          }
          System.out.printf("%-20s %-40s\n", tokenType, tokens.toString());
     }
}