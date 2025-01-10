#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;
    LinkedList() : head(nullptr) {}

    void Insert_front(int value) {
        if (Size() <= 10) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        } else {
            cout << "\nSize Overflow. Cannot insert at the front.\n";
        }
    }

    void Insert_Last(int value) {
        if (Size() <= 10) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = nullptr;
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        } else {
            cout << "\nSize Overflow. Cannot insert at the end.\n";
        }
    }

    void InsertAtLocation(int value, int pos) {
        Node* newNode = new Node();
        newNode->data = value;

        if (Size() <= 10) {
            if (pos == 1) {
                newNode->next = head;
                head = newNode;
                return;
            }

            Node* temp = head;
            for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }

            if (temp == nullptr) {
                cout << "Position out of bound. Inserted at the end.\n";
                Insert_Last(value);
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        } else {
            cout << "\nSize Overflow. Cannot insert at location.\n";
        }
    }

    int DeleteFront() {
        if (head == nullptr) return -1;
        Node* temp = head;
        int deleted = temp->data;
        head = head->next;
        delete temp;
        return deleted;
    }

    int DeleteLast() {
        if (head == nullptr) return -1;
        if (head->next == nullptr) {
            int deleted = head->data;
            delete head;
            head = nullptr;
            return deleted;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            int deleted = temp->next->data;
            delete temp->next;
            temp->next = nullptr;
            return deleted;
        }
    }

    int DeleteAtLocation(int pos) {
        if (head == nullptr) return -1;
        if (pos == 1) {
            int deleted = head->data;
            Node* temp = head;
            head = head->next;
            delete temp;
            return deleted;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bound.";
            return -1;
        } else {
            Node* NodeToDelete = temp->next;
            int deleted = NodeToDelete->data;
            temp->next = NodeToDelete->next;
            delete NodeToDelete;
            return deleted;
        }
    }

    int Size() {
        Node* temp = head;
        int size = 0;
        while (temp != nullptr) {
            temp = temp->next;
            size++;
        }
        return size;
    }

    void Remove_Duplicate() {
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            Node* runner = current;
            while (runner->next != nullptr) {
                if (current->data == runner->next->data) {
                    Node* DuplicateNode = runner->next;
                    runner->next = runner->next->next;
                    delete DuplicateNode;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

void insertInOrder(int newData) {
    // Check if the list has reached the maximum size
    if (Size() >= 10) {
        cout << "\nSize Overflow. Cannot insert in order.\n";
        return;
    }

    // Create a new node with the given data
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    // Case 1: Insert at the beginning if the list is empty or newData is smaller than the head's data
    if (head == nullptr||head->data >= newData ) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Traverse to find the correct position for the new node
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data < newData) {
        temp = temp->next;
    }

    // Insert the new node in the correct position
    newNode->next = temp->next;
    temp->next = newNode;
}

    void Display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main() {
    LinkedList list;
    // list.Insert_front(13);
    // list.Insert_front(32);
    // list.Insert_front(23);
    // list.Insert_Last(63);
    // list.Remove_Duplicate();
    list.insertInOrder(4);
    list.insertInOrder(19);
    list.insertInOrder(14);
    list.Display();
    cout << "\nList total number (counter) is " << list.Size();
}
