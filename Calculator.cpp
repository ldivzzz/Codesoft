#include <iostream>

using namespace std;

int main() {
    char operation;
    float num1, num2, result;

    // Prompt user for input
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Prompt user to choose operation
    cout << "Choose operation (+, -, *, /): ";
    cin >> operation;

    // Perform operation based on user's choice
    switch(operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result;
            break;
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result;
            } else {
                cout << "Error! Division by zero!";
            }
            break;
        default:
            cout << "Invalid operation!";
    }

    return 0;
}

