#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

// Node structure for Expression Tree
struct Node {
    char data;
    Node* left;
    Node* right;
    
    Node(char value) {
        data = value;
        left = right = nullptr;
    }
};

// Expression Tree Class
class ExpressionTree {
private:
    Node* root;

    void preorder(Node* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

public:
    ExpressionTree() {
        root = nullptr;
    }

    // Construct Expression Tree from Postfix Expression
    void constructTree(string postfix) {
        stack<Node*> s;

        for (char ch : postfix) {
            if (isalnum(ch)) { // Operand (number or variable)
                s.push(new Node(ch));
            } else { // Operator
                Node* newNode = new Node(ch);
                newNode->right = s.top(); s.pop();
                newNode->left = s.top(); s.pop();
                s.push(newNode);
            }
        }

        root = s.top();
    }

    // Traversal Functions
    void displayPreorder() { preorder(root); cout << endl; }
    void displayInorder() { inorder(root); cout << endl; }
    void displayPostorder() { postorder(root); cout << endl; }
};

int main() {
    ExpressionTree expTree;
    string postfix;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter Postfix Expression\n";
        cout << "2. Construct Expression Tree\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                expTree.constructTree(postfix);
                cout << "Expression Tree Constructed.\n";
                break;
            case 3:
                cout << "Preorder Traversal: ";
                expTree.displayPreorder();
                break;
            case 4:
                cout << "Inorder Traversal: ";
                expTree.displayInorder();
                break;
            case 5:
                cout << "Postorder Traversal: ";
                expTree.displayPostorder();
                break;
            case 6:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}
