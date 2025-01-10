#include <iostream>
using namespace std;

#define MAX 10

class List {
    string Title[MAX];
    string Id[MAX];
    double Price[MAX]; // Changed to double to accommodate decimal prices
    string Author[MAX];
    int size;

public:
    List() : size(0) {}

    void add(const string& t, const string& i, double p, const string& a) {
        if (size < MAX) {
            Title[size] = t;
            Id[size] = i;
            Price[size] = p;
            Author[size] = a;
            size++;
        } else {
            cout << "List is full" << endl;
        }
    }

    void Delete() {
        if (size > 0) {
            for (int i = 0; i < size - 1; i++) {
                Title[i] = Title[i + 1];
                Id[i] = Id[i + 1];
                Price[i] = Price[i + 1];
                Author[i] = Author[i + 1];
            }
            size--;
        } else {
            cout << "List is empty" << endl;
        }
    }

    void insertAtLocation(const string& t, const string& i, double p, const string& a, int pos) {
        if (pos <= size && size < MAX) {
            for (int j = size; j > pos; j--) {
                Title[j] = Title[j - 1];
                Id[j] = Id[j - 1];
                Price[j] = Price[j - 1];
                Author[j] = Author[j - 1];
            }
            Title[pos] = t;
            Id[pos] = i;
            Price[pos] = p;
            Author[pos] = a;
            size++;
        } else {
            cout << "Position out of range or list is full" << endl;
        }
    }

    void deleteAtLocation(int pos) {
        if (pos >= 0 && pos < size) { 
            for (int i = pos; i < size - 1; i++) {
                Title[i] = Title[i + 1];
                Id[i] = Id[i + 1];
                Price[i] = Price[i + 1];
                Author[i] = Author[i + 1];
            }
            size--; 
            cout << "\nDeleted item at position " << pos + 1 << endl;
        } else {
            cout << "\nPosition out of range" << endl;
        }
    }

    int getSize() {
        return size;
    }

    void Display() {
        for (int i = 0; i < size; i++) {
            cout << "Title: " << Title[i]
                << ", ID: " << Id[i]
            << ", Price: $" << Price[i]
            << ", Author: " << Author[i] << endl;
        }
    }
};

int main() {
    List p;
    p.add("Search Name", "8225", 500, "Awais");
    p.insertAtLocation("Harry Potter", "1234", 10.99, "J.K. Rowling", 1);
    p.insertAtLocation("The Lord of the Rings", "5678", 12.99, "J.R.R. Tolkien", 2);
    cout << "\n\nList of books:" << endl;
    p.Display();

    cout << "\n\nAfter deleting at position 3:" << endl;
    p.deleteAtLocation(2); 
    p.Display();

    return 0;
}
