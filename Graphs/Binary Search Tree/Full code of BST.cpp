#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct BST {
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* insert(Node* root, int data) {
        if (root == nullptr) {
            Node* newNode = new Node();
            newNode->data = data;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }

    void insert(int data) {
        root = insert(root, data);
    }

    bool search(Node* root, int x) {
        if (root == nullptr) {
            return false;
        } else if (root->data == x) {
            return true;
        } else if (x < root->data) {
            return search(root->left, x);
        } else {
            return search(root->right, x);
        }
    }

    bool search(int data) {
        return search(root, data);
    }

    Node* Delete(Node* root, int data) {
        if (root == nullptr) {
            return nullptr;
        }
        if (data < root->data) {
            root->left = Delete(root->left, data);
        } else if (data > root->data) {
            root->right = Delete(root->right, data);
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* temp = root->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
        }
        return root;
    }

    void Delete(int data) {
        root = Delete(root, data);
    }

    void preorder(Node* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void preorder() {
        preorder(root);
    }

    void inorder(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void inorder() {
        inorder(root);
    }
};

int main() {
    BST b;
    int choice;
    int x;

    do {
        cout << "BST\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Preorder\n";
        cout << "5. Inorder\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> x;
                b.insert(x);
                break;
            case 2:
                cout << "Enter the element to be deleted: ";
                cin >> x;
                b.Delete(x);
                break;
            case 3:
                cout << "Enter the element to be searched: ";
                cin >> x;
                if (b.search(x)) {
                    cout << "Element found\n";
                } else {
                    cout << "Element not found\n";
                }
                break;
            case 4:
                cout << "Preorder traversal: ";
                b.preorder();
                cout << endl;
                break;
            case 5:
                cout << "Inorder traversal: ";
                b.inorder();
                cout << endl;
                break;
            case 6:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
