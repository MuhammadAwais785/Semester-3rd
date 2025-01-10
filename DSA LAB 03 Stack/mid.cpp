#include <iostream>
#include <string>
using namespace std;
#define N 100
class Stack {
    string containers[N];
    int top;

public:
    Stack()  {
        top=-1;
    }

    bool isFull(){
        return top+1==N;
    }

    bool isEmpty(){
        return top==-1;
    }

    void push(string id) {
        if (isFull()) {
            cout << "Stack is full! Cannot add container.\n";
            return;
        }
        containers[++top] = id;
        cout << "Container " << id << " added.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to remove.\n";
            return;
        } 
        cout << "Container " << containers[top] << " removed.\n";
        top--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Current Stack: ";
        for (int i = top; i >= 0; --i) {
            cout << containers[i] << " ";
        }
        cout << endl;
    }

    void retrievePriority(string priorityID) {
        string tempStack[100];
        int tempTop = -1;
        bool found = false;

        
        while (top != -1) {
            if (containers[top] == priorityID) {
                cout << "Priority container " << priorityID << " retrieved.\n";
                top--;
                found = true;
                break;
            } else {
                tempStack[++tempTop] = containers[top--];
            }
        }

        // Restore the original stack
        while (tempTop != -1) {
            containers[++top] = tempStack[tempTop--];
        }

        if (!found) {
            cout << "Priority container " << priorityID << " not found.\n";
        }
    }
};

int main() {
    Stack stack;
    int choice;
    string id;
    string Id;

    do {
        cout << "\n1. Push Container\n2. Pop Container\n3. Display Stack\n4. Retrieve Priority Container\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter container ID to push: ";
            cin >> id;
            stack.push(id);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.display();
            break;
        case 4:
            
            cout << "Enter priority container ID: ";
            cin >> Id;
            stack.retrievePriority(Id);
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! try again\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
