#include <iostream>
using namespace std;

// Define the structure for a node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Define the Tree structure
struct Tree {
    Node* root;

    // Constructor to initialize the tree
    Tree() {
        root = nullptr;
    }

    // Function to insert a node as the root
    void InsertRoot(int value) {
        if (root == nullptr) {
            root = new Node();
            root->data = value;
            root->left = nullptr;
            root->right = nullptr;
        } else {
            cout << "Root already exists!" << endl;
        }
    }

    // Function to find a node by value
    Node* FindNode(Node* current, int value) {
        if (current == nullptr || current->data == value) {
            return current;
        }
        Node* found = FindNode(current->left, value);
        if (found == nullptr) {
            found = FindNode(current->right, value);
        }
        return found;
    }

    // Function to insert a node to the left of a given parent
    void InsertLeft(Node* parent, int x) {
        if (parent != nullptr) {
            if (parent->left == nullptr) {
                Node* newNode = new Node();
                newNode->data = x;
                newNode->left = nullptr;
                newNode->right = nullptr;
                parent->left = newNode;
            } else {
                cout << "Left child of node " << parent->data << " already exists!" << endl;
            }
        } else {
            cout << "Parent node not found!" << endl;
        }
    }

    // Function to insert a node to the right of a given parent
    void InsertRight(Node* parent, int x) {
        if (parent != nullptr) {
            if (parent->right == nullptr) {
                Node* newNode = new Node();
                newNode->data = x;
                newNode->left = nullptr;
                newNode->right = nullptr;
                parent->right = newNode;
            } else {
                cout << "Right child of node " << parent->data << " already exists!" << endl;
            }
        } else {
            cout << "Parent node not found!" << endl;
        }
    }

    // Preorder traversal: Visit root, left subtree, right subtree
    void Preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";  // Visit root
        Preorder(node->left);      // Recur on left
        Preorder(node->right);     // Recur on right
    }

    // Inorder traversal: Visit left subtree, root, right subtree
    void Inorder(Node* node) {
        if (node == nullptr) return;
        Inorder(node->left);       // Recur on left
        cout << node->data << " "; // Visit root
        Inorder(node->right);      // Recur on right
    }

    // Postorder traversal: Visit left subtree, right subtree, root
    void Postorder(Node* node) {
        if (node == nullptr) return;
        Postorder(node->left);     // Recur on left
        Postorder(node->right);    // Recur on right
        cout << node->data << " "; // Visit root
    }

    // Wrapper functions for traversals
    void PreorderTraversal() {
        Preorder(root);
        cout << endl; 
        }
    void InorderTraversal() {
        Inorder(root); 
        cout << endl;
        }
    void PostorderTraversal() {
        Postorder(root); 
        cout << endl; 
        }
};

int main() {
    Tree t;
    int choice, value, parentValue;
    Node* parent = nullptr;

    do {
        cout << "\n--- Binary Tree Menu ---" << endl;
        cout << "1. Insert as Root" << endl;
        cout << "2. Insert Left Child" << endl;
        cout << "3. Insert Right Child" << endl;
        cout << "4. Preorder Traversal" << endl;
        cout << "5. Inorder Traversal" << endl;
        cout << "6. Postorder Traversal" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value for root: ";
                cin >> value;
                t.InsertRoot(value);
                break;

            case 2:
                cout << "Enter value of parent node: ";
                cin >> parentValue;
                cout << "Enter value for left child: ";
                cin >> value;
                parent = t.FindNode(t.root, parentValue);
                t.InsertLeft(parent, value);
                break;

            case 3:
                cout << "Enter value of parent node: ";
                cin >> parentValue;
                cout << "Enter value for right child: ";
                cin >> value;
                parent = t.FindNode(t.root, parentValue);
                t.InsertRight(parent, value);
                break;

            case 4:
                cout << "Preorder Traversal: ";
                t.PreorderTraversal();
                break;

            case 5:
                cout << "Inorder Traversal: ";
                t.InorderTraversal();
                break;

            case 6:
                cout << "Postorder Traversal: ";
                t.PostorderTraversal();
                break;

            case 7:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
