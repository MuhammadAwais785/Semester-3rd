#include<iostream>
using namespace std;

int STACKSIZE;

class Stack {
    private:
        char *arr;
        int top;
    public:
        void push(int x);
        char pop();
        bool full();
        bool empty();
        int size();    
        void Display();
        Stack(int STACKSIZE);
};

Stack::Stack(int STACKSIZE) {
    top = -1;
    arr = new char[STACKSIZE];
}

void Stack::push(int x) {
    if (!full()) {
        arr[++top] = x;
    } else {
        cout << " Stack Overflow ";
    }
}

char Stack::pop() {
    if (!empty()) {
        return arr[top--];
    } else {
        cout << " Stack is empty ";
        return '\0';  // Return null character if stack is empty
    }
}

bool Stack::full() {
    return top + 1 == STACKSIZE;
}

bool Stack::empty() {
    return top == -1;
}

int Stack::size() {
    return top + 1;
}

void Stack::Display() {
    if (empty()) {
        cout << " Stack underflow ";
    } else {
        for (int i = top; i >= 0; i--) {  // Correct loop to display only valid elements
            cout << arr[i] << " ";
        }
    }
}

int main() {
    cout << "Enter size: ";
    cin >> STACKSIZE;

    Stack stack(STACKSIZE);
    char val;

    cout << "Enter values: ";
    for (int i = 0; i < STACKSIZE; i++) {
        cin >> val;
        stack.push(val);
    }

    cout << "\nPopped: " << stack.pop() << endl;
	cout<<" Remaining Stack is ";
    stack.Display();
    cout << "\nSize of stack: " << stack.size();

    return 0;
}
