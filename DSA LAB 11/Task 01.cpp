#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string ISBN;
    string author_name;
    int edition;

public:
    // Constructor
    Book() : ISBN(""), author_name(""), edition(0) {}

    Book(string isbn, string author, int ed) : ISBN(isbn), author_name(author), edition(ed) {}

    // Input function
    void input() {
        cout << "Enter ISBN: ";
        cin >> ISBN;
        cout << "Enter Author Name: ";
        cin.ignore();
        getline(cin, author_name);
        cout << "Enter Edition: ";
        cin >> edition;
    }

    // Output function
    void output() const {
        cout << "ISBN: " << ISBN << ", Author: " << author_name << ", Edition: " << edition << endl;
    }

    // Get ISBN
    string getISBN() const {
        return ISBN;
    }
};

class BinaryTree {
private:
    vector<Book> tree;

    // Helper functions for traversal
    void preOrder(int index) const {
        if (index >= tree.size() || tree[index].getISBN() == "")
            return;
        tree[index].output();
        preOrder(2 * index + 1);
        preOrder(2 * index + 2);
    }

    void inOrder(int index) const {
        if (index >= tree.size() || tree[index].getISBN() == "")
            return;
        inOrder(2 * index + 1);
        tree[index].output();
        inOrder(2 * index + 2);
    }

    void postOrder(int index) const {
        if (index >= tree.size() || tree[index].getISBN() == "")
            return;
        postOrder(2 * index + 1);
        postOrder(2 * index + 2);
        tree[index].output();
    }

public:
    // Constructor
    BinaryTree() {
        tree.resize(1); // Initialize with a single root node
    }

    // Insert function
    void insert(const Book& book) {
        for (size_t i = 0; i < tree.size(); ++i) {
            if (tree[i].getISBN() == "") {
                tree[i] = book;
                return;
            }
        }
        // If tree is full, resize and insert
        tree.push_back(book);
    }

    // Delete function
    void deleteBook(const string& isbn) {
        for (size_t i = 0; i < tree.size(); ++i) {
            if (tree[i].getISBN() == isbn) {
                tree[i] = Book(); // Reset the node to empty
                cout << "Book deleted successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    // Search function
    void search(const string& isbn) const {
        for (size_t i = 0; i < tree.size(); ++i) {
            if (tree[i].getISBN() == isbn) {
                cout << "Book found: \n";
                tree[i].output();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    // Traversal functions
    void preOrderTraversal() const {
        cout << "Pre-order Traversal:\n";
        preOrder(0);
    }

    void inOrderTraversal() const {
        cout << "In-order Traversal:\n";
        inOrder(0);
    }

    void postOrderTraversal() const {
        cout << "Post-order Traversal:\n";
        postOrder(0);
    }
};

int main() {
    BinaryTree tree;
    int choice;
    do {
        cout << "\nMenu:\n1. Insert Book\n2. Delete Book\n3. Search Book\n4. Pre-order Traversal\n5. In-order Traversal\n6. Post-order Traversal\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Book book;
            book.input();
            tree.insert(book);
            break;
        }
        case 2: {
            string isbn;
            cout << "Enter ISBN to delete: ";
            cin >> isbn;
            tree.deleteBook(isbn);
            break;
        }
        case 3: {
            string isbn;
            cout << "Enter ISBN to search: ";
            cin >> isbn;
            tree.search(isbn);
            break;
        }
        case 4:
            tree.preOrderTraversal();
            break;
        case 5:
            tree.inOrderTraversal();
            break;
        case 6:
            tree.postOrderTraversal();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}