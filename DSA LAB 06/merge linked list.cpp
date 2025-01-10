#include<iostream>
using namespace std;

// Structure for Node
struct Node {
    string name;
    Node* next;
};

// LinkedList class to manage student data
struct LinkedList {
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to insert a student at the front
    void InsertFront(string studentName) {
        Node* newNode = new Node();
        newNode->name = studentName;
        newNode->next = head;
        head = newNode;
    }

    // Function to display the list of students
    void Display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to combine two lists
    LinkedList MergeLists(LinkedList& list1, LinkedList& list2) {
        LinkedList mergedList;
        
        Node* temp = list1.head;
        while (temp != nullptr) {
            mergedList.InsertFront(temp->name); // Insert at front to maintain order
            temp = temp->next;
        }

        temp = list2.head;
        while (temp != nullptr) {
            mergedList.InsertFront(temp->name); // Insert at front to maintain order
            temp = temp->next;
        }

        return mergedList; // Return merged list
    }
};

// Main function to execute the program
int main() {
    LinkedList pakistaniStudents;
    LinkedList indianStudents;

    // Inserting Pakistani students
    pakistaniStudents.InsertFront("Ali");
    pakistaniStudents.InsertFront("Ahmed");
    pakistaniStudents.InsertFront("Sana");

    // Inserting Indian students
    indianStudents.InsertFront("Raj");
    indianStudents.InsertFront("Priya");
    indianStudents.InsertFront("Ravi");

    // Printing Pakistani students list
    cout << "Pakistani Students: ";
    pakistaniStudents.Display();

    // Printing Indian students list
    cout << "Indian Students: ";
    indianStudents.Display();

    // Merging and printing both lists
    LinkedList allStudents = pakistaniStudents.MergeLists(pakistaniStudents, indianStudents);
    cout << "All Students: ";
    allStudents.Display();

    return 0;
}
