#include<iostream>
using namespace std;
#define N 5

class Stack {
    int top;
    int arr[N];
public:
    Stack() { top = -1; }  // Constructor
    ~Stack() {}            // Destructor

    void push() {
        int value;
        if (!isFull()) {
            cout << "Enter value to push in stack: ";
            cin >> value;
            arr[++top] = value;
            cout << "Value pushed in stack: " << value << endl;
        } else {
            cout << "Stack is full" << endl;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == N - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack MyStack;
    int choice;
    do {
        cout << "MENU\n";
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Display stack\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                MyStack.push();
                break;
            case 2:
                int Pop;
                Pop = MyStack.pop();
                if (Pop != -1) {
                    cout << Pop << " popped from stack" << endl;
                }
                break;
            case 3:
                MyStack.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!. try again " << endl;
                break;
        }
    } while (true);

    return 0;
}
