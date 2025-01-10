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
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertInMiddle(int reg_no, string name, float cgpa, string city, int age, int position) {
        if (position < 0) {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 0) {
            insertAtFront(reg_no, name, cgpa, city, age);
            return;
        }
        Node* newNode = new Node();
        newNode->reg_no = reg_no;
        newNode->name = name;
        newNode->cgpa = cgpa;
        newNode->city = city;
        newNode->age = age;
        Node* current = head;
    	for(int i=1;i<position-1&&current->next!=NULL;i++){
    		current=current->next;
		}
        if (current == NULL) {
            insertAtRear(reg_no, name, cgpa, city, age);
        } else {
            newNode->prev = current;
            newNode->next = current->next;
            if (current->next) {
                current->next->prev = newNode;
            } else {
                tail = newNode;
            }
            current->next = newNode;
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
        if (position < 0) {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 0) {
            deleteFromFront();
            return;
        }
        Node* current = head;
        for(int i=1;i<position-1&&current->next!=NULL;i++){
    	current=current->next;
		}
        if (current == NULL || current->next == NULL) {
            deleteFromRear();
        } else {
            Node* temp = current->next;
            current->next = current->next->next;
            if (current->next) {
                current->next->prev = current;
            } else {
                tail = current;
            }
            delete temp;
        }
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
    list.insertAtFront(16,"AWAIS",3.76,"LEEPA",19);
    list.displayAll();
	cout<<endl;	
    list.insertAtRear(16,"Ali",3.76,"MZD",19);
    list.displayAll();
    list.insertInMiddle(23,"ywud",3.78,"hjdj",40,2);
    list.displayAll();
}