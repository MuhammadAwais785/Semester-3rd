#include<iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int size;

public:
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (isFull()) {
            cout << " Stack Overflow ";
        } else {
            arr[++top] = x;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << " Stack is Empty ";
            return -1;
        } else {
            return arr[top--];
        }
    }

    bool isFull() {
        return top + 1 == size;
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        if (isEmpty()) {
            cout << " Stack is Empty ";
        } else {
            cout << " Elements in Stack: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void nextLarger() {
        if (isEmpty()) {
            cout << " Stack is Empty ";
        } else {
            int nearest = -1;
            int value;
            cout << " Enter value to find the next larger element: ";
            cin >> value;

            for (int i = 0; i <= top; i++) {
                if (arr[i] > value) {
                    if (nearest == -1 || arr[i] < nearest) {
                        nearest = arr[i];
                    }
                }
            }

            if (nearest == -1) {
                cout << " No larger element present " << endl;
            } else {
                cout << " Larger element is " << nearest << endl;
            }
        }
    }
};

int main() {
    int size;
    cout << " Enter size of the stack: ";
    cin >> size;

    Stack s1(size);

    do {
        int choice;
        cout << "\nMenu:\n";
        cout << "1. PUSH a value in Stack\n";
        cout << "2. POP a value from Stack\n";
        cout << "3. Display the Stack\n";
        cout << "4. Show the next greater element in the Stack\n";
        cout << "Enter your choice (1-4), or press any other key to exit: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter a value to push: ";
                cin >> value;
                s1.push(value);
                break;
            }

            case 2: {
                int poppedValue = s1.pop();
                if (poppedValue != -1)
                    cout << poppedValue << " popped value from stack.\n";
                break;
            }

            case 3:
                s1.display();
                break;

            case 4:
                s1.nextLarger();
                break;

            default:
                return 0;
        }
    } while (true);
 return 0;
}
