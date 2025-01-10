#include <iostream>
using namespace std;

struct Node {
    int reg_no;
    string name;
    float cgpa;
    string city;
    int age;
    Node* prev;
    Node* next;
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtFront(int reg_no, string name, float cgpa, string city, int age) {
        Node* newNode = new Node();
        newNode->reg_no = reg_no;
        newNode->name = name;
        newNode->cgpa = cgpa;
        newNode->city = city;
        newNode->age = age;
        newNode->prev = NULL;
        newNode->next = NULL;
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtRear(int reg_no, string name, float cgpa, string city, int age) {
        Node* newNode = new Node();
        newNode->reg_no = reg_no;
        newNode->name = name;
        newNode->cgpa = cgpa;
        newNode->city = city;
        newNode->age = age;
        newNode->prev = tail;
        newNode->next = NULL;
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void InsertAtLocation(int reg_no, string name, float cgpa, string city, int age,int position){
        Node*newNode = new Node();
        newNode->reg_no = reg_no;
        newNode->name = name;
        newNode->cgpa = cgpa;
        newNode->city = city;
        newNode->age = age;
        if(position==1){
            insertAtFront(reg_no,name,cgpa,city,age);
            return;
        }
        Node*temp=head;
        for(int i=1;i<position-1&&temp!=nullptr;i++){
            temp=temp->next;
        }
        if(temp==nullptr){
            cout<<" Position is out of bound ";
            return;
        }else{
            newNode->next=temp->next;
            newNode->prev=temp;
                if (temp->next != nullptr) { 
            temp->next->prev = newNode;
            } else { 
                tail = newNode;
            }
            temp->next=newNode;
        }
    }

    void deleteFromFront() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }

    void deleteFromRear() {
        if (tail == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }

    void deleteFromMiddle(int position) {
     if (head == nullptr) { // Handle empty list
        cout << "List is empty" << endl;
        return;
    }

    if (position == 1) { // Handle deletion of the first node
        deleteFromFront();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) { // Position out of bounds
        cout << "Position out of bounds" << endl;
        return;
    }

    if (temp->next != nullptr) { // Update next node's previous pointer
        temp->next->prev = temp->prev;
    } else { // If deleting the last node, update the tail
        tail = temp->prev;
    }

    if (temp->prev != nullptr) { // Update previous node's next pointer
        temp->prev->next = temp->next;
    }

    delete temp; // Delete the node
    cout << "Node at position " << position << " deleted." << endl;
}

    void displayAll() {
        Node* current = head;
        while (current!=NULL) {
            cout << "Reg No: " << current->reg_no << ", Name: " << current->name << ", CGPA: " << current->cgpa << ", City: " << current->city << ", Age: " << current->age << endl;
            current = current->next;
        }
    }
};
int main() {
    DoublyLinkedList list;
    int choice;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Insert at Specific Location\n";
        cout << "4. Delete from Front\n";
        cout << "5. Delete from Rear\n";
        cout << "6. Delete from Specific Location\n";
        cout << "7. Display All\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int reg_no, age;
                string name, city;
                float cgpa;
                cout << "Enter Reg No: ";
                cin >> reg_no;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter CGPA: ";
                cin >> cgpa;
                cout << "Enter City: ";
                cin >> city;
                cout << "Enter Age: ";
                cin >> age;
                list.insertAtFront(reg_no, name, cgpa, city, age);
                break;
            }
            case 2: {
                int reg_no, age;
                string name, city;
                float cgpa;
                cout << "Enter Reg No: ";
                cin >> reg_no;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter CGPA: ";
                cin >> cgpa;
                cout << "Enter City: ";
                cin >> city;
                cout << "Enter Age: ";
                cin >> age;
                list.insertAtRear(reg_no, name, cgpa, city, age);
                break;
            }
            case 3: {
                int reg_no, age, position;
                string name, city;
                float cgpa;
                cout << "Enter Reg No: ";
                cin >> reg_no;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter CGPA: ";
                cin >> cgpa;
                cout << "Enter City: ";
                cin >> city;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Position: ";
                cin >> position;
                list.InsertAtLocation(reg_no, name, cgpa, city, age, position);
                break;
            }
            case 4:
                list.deleteFromFront();
                break;
            case 5:
                list.deleteFromRear();
                break;
            case 6: {
                int position;
                cout << "Enter Position to Delete: ";
                cin >> position;
                list.deleteFromMiddle(position);
                break;
            }
            case 7:
                list.displayAll();
                break;
            case 8:
                cout << "Exiting program.\n";
                return 1;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 8);

    return 0;
}