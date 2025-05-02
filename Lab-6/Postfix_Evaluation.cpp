//Menu Driven Function to implement Infix to Postfix and Postfix Evaluation
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>

using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack() {
        while (!isEmpty()) pop();
    }

    void push(T value) {
        Node* newNode = new Node{value, topNode};
        topNode = newNode;
    }

    T pop() {
        if (isEmpty()) throw runtime_error("Stack Underflow");
        T value = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return value;
    }

    T top() const {
        if (isEmpty()) throw runtime_error("Stack is Empty");
        return topNode->data;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }
};

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(const string &infix) {
    Stack<char> stack;
    string postfix;
    
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;  // Append operands to postfix expression
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.top() != '(') {
                postfix += stack.pop();
            }
            stack.pop(); // Remove '(' from stack
        } else {
            while (!stack.isEmpty() && precedence(stack.top()) >= precedence(ch)) {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
    }
    
    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }
    
    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string &postfix) {
    Stack<int> stack;
    
    for (char ch : postfix) {
        if (isdigit(ch)) {
            stack.push(ch - '0'); // Convert char to int
        } else {
            int val2 = stack.pop();
            int val1 = stack.pop();
            switch (ch) {
                case '+': stack.push(val1 + val2); break;
                case '-': stack.push(val1 - val2); break;
                case '*': stack.push(val1 * val2); break;
                case '/': stack.push(val1 / val2); break;
            }
        }
    }
    return stack.pop();
}

int main() {
    string infix;
    string postfix;
    int choice;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Get Infix Expression\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character
        
        switch (choice) {
            case 1:
                cout << "Enter a valid infix expression: ";
                getline(cin, infix);
                break;
            case 2:
                if (infix.empty()) {
                    cout << "Please enter an infix expression first.\n";
                } else {
                    postfix = infixToPostfix(infix);
                    cout << "Postfix Expression: " << postfix << "\n";
                }
                break;
            case 3:
                if (postfix.empty()) {
                    cout << "Please convert infix to postfix first.\n";
                } else {
                    cout << "Evaluation Result: " << evaluatePostfix(postfix) << "\n";
                }
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
    
    return 0;
}
