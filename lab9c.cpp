#include <cstdio>
#include <cstdlib>

class BST {
private:
    struct node {
        int data;
        struct node *left, *right;
    } *root;

    node* insert(node* root, int value);
    void preorder(node* root);
    void inorder(node* root);
    void postorder(node* root);
    node* search(node* root, int target);

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void preorder() {
        preorder(root);
        printf("\n");
    }

    void inorder() {
        inorder(root);
        printf("\n");
    }

    void postorder() {
        postorder(root);
        printf("\n");
    }

    bool search(int target) {
        return search(root, target) != NULL;
    }
};

int main() {
    BST tree;
    int choice, target;

    do {
        printf("\nMenu Driven Program\n");
        printf("1) Insert\n2) Preorder\n3) Inorder\n4) Postorder\n5) Search\n6) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &target);
                tree.insert(target);
                break;
            case 2:
                tree.preorder();
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.postorder();
                break;
            case 5:
                printf("Enter a target to be found: ");
                scanf("%d", &target);
                if (tree.search(target)) {
                    printf("Target found.\n");
                } else {
                    printf("Target not found.\n");
                }
                break;
            case 6:
                printf("Exiting Program...\n");
                return 0;
            default:
                printf("Enter a valid choice.\n");
        }
    } while (choice != 6);
}

// Recursive insert function
BST::node* BST::insert(node* root, int value) {
    if (root == NULL) {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->data = value;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Recursive preorder traversal
void BST::preorder(node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Recursive inorder traversal
void BST::inorder(node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Recursive postorder traversal
void BST::postorder(node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Recursive search function
BST::node* BST::search(node* root, int target) {
    if (root == NULL || root->data == target) {
        return root;
    }

    if (target < root->data) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}
