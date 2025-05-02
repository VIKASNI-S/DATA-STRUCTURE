//Menu driven program to implement Binary tree and its traversals
#include <iostream>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(char val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    TreeNode* root;
    
    BinaryTree() {
        root = nullptr;
    }
    //To insert a node
    void insert(char val) {
        root = insertRec(root, val);
    }
    //To perform Preorder
    void preorder() {
        preorderRec(root);
        cout << endl;
    }
    //To perform Inorder
    void inorder() {
        inorderRec(root);
        cout << endl;
    }
    //To perform Postorder
    void postorder() {
        postorderRec(root);
        cout << endl;
    }
    //To search
    bool search(char val) {
        return searchRec(root, val);
    }
    
private:
    TreeNode* insertRec(TreeNode* node, char val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->data) {
            node->left = insertRec(node->left, val);
        } else {
            node->right = insertRec(node->right, val);
        }
        return node;
    }
    
    void preorderRec(TreeNode* node) {
        if (node) {
            cout << node->data << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }
    
    void inorderRec(TreeNode* node) {
        if (node) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }
    
    void postorderRec(TreeNode* node) {
        if (node) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " ";
        }
    }
    
    bool searchRec(TreeNode* node, char val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return searchRec(node->left, val);
        return searchRec(node->right, val);
    }
};

int main() {
    BinaryTree tree;
    int choice;
    char val;
    
    do {
        cout << "\nBinary Tree Menu";
        cout << "\n1. Insert";
        cout << "\n2. Preorder";
        cout << "\n3. Inorder";
        cout << "\n4. Postorder";
        cout << "\n5. Search";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter character to insert: ";
                cin >> val;
                tree.insert(val);
                break;
            case 2:
                cout << "Preorder traversal: ";
                tree.preorder();
                break;
            case 3:
                cout << "Inorder traversal: ";
                tree.inorder();
                break;
            case 4:
                cout << "Postorder traversal: ";
                tree.postorder();
                break;
            case 5:
                cout << "Enter character to search: ";
                cin >> val;
                if (tree.search(val))
                    cout << "Element found" << endl;
                else
                    cout << "Element not found" << endl;
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 6);
    
    return 0;
}
