#include <iostream>
using namespace std;
#define N 5

int rear = -1;
int front = -1;
int Queue[N];
int dequeueSum = 0;   // To track sum of dequeued elements
int dequeueCount = 0; // To track count of dequeued elements

void enQueue(int val) {
    if ((rear + 1) % N == front) {
        cout << "Queue is full" << endl;
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        Queue[rear] = val;

    } else {
        rear = (rear + 1) % N;
        Queue[rear] = val;
    }
}

int Dequeue() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty" << endl;
        return -1;
    } else {
        int temp = Queue[front];             
        dequeueSum += temp;   
        dequeueCount++;       
        if (rear == front) {
            front = rear = -1;
        } else {
            front = (front + 1) % N;
        }
        return temp;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty" << endl;
    } else {
        for(int i=front;i<=rear;i=(i+1)%N){
                cout<<Queue[i]<<" ";
            }
    }
}

double dequeuedAverage() {
    if (dequeueCount == 0) {  
        cout << "No elements have been dequeued." << endl;
        return 0;
    }
    return static_cast<double>(dequeueSum) / dequeueCount;
}

int main() {
    int choice, item;
    while (1) {
        cout << "\n1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Average of Dequeued Elements" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter Element to Enqueue: ";
                cin >> item;
                enQueue(item);
                break;
            case 2:
                int deQueued;
                deQueued = Dequeue();
                if (deQueued != -1)
                    cout << deQueued << " DeQueued" << endl;
                break;
            case 3:
                cout << "Queue is: ";
                display();
                break;
            case 4:
                cout << "Average of dequeued elements is: " << dequeuedAverage() << endl;
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid Choice" << endl;
        }
    }
}
