#include<iostream>
using namespace std;
#define N 5
class DEQUEUE{
    int Queue[N];
    int front, rear;
    public:
    DEQUEUE(){
        front = rear = -1;
        }

    void EnqueueFront(int x){
        if((rear+1)%N==front){
            cout<<"Queue is full"<<endl;
        }else{
            if(front==-1)
            {
                front = rear = 0;
                Queue[front]=x;
            }else{
                front = (front-1+N)%N;
                Queue[front]=x;
            }
        }
    }

    void EnqueueRear(int x){
        if((rear+1)%N==front){
            cout<<"Queue is full"<<endl;
        }else{
            if(rear==-1)
            {
                front = rear = 0;
                Queue[rear]=x;
            }else{
                rear = (rear+1)%N;
                Queue[rear]=x;
            }
        }
    }

    void DequeueFront(){
        if(front==-1&&rear==-1){
            cout<<"Queue is empty"<<endl;
        }else{
            if(front==rear){
                front = rear = -1;
            }else{
                front = (front+1)%N;
            }
        }
    }

    void DequeueRear(){
        if(front==-1&&rear==-1){
            cout<<"Queue is empty"<<endl;
        }else{
            if(front==rear){
                front = rear = -1;
                }else
                {
                    rear = (rear-1+N)%N;
                }
        }
    }
    void Display(){
        if(front==-1&&rear==-1){
            cout<<"Queue is empty"<<endl;
            return;
            }
            else{
                for (int i = front; i != rear; i = (i + 1) % N) {
            cout << Queue[i] << " ";
        }
        cout << Queue[rear] << endl;
        }
    }
};
int main(){
    DEQUEUE q;
    q.EnqueueFront(10);
    q.EnqueueFront(20);
    q.EnqueueRear(30);
    q.EnqueueRear(40);
    q.Display();
    q.DequeueFront();
    q.Display();
    q.DequeueRear();
    q.Display();
}