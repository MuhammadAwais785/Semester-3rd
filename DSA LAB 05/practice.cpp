#include<iostream>
using namespace std;
#define N 5
int rear=-1;
int front=-1;
int Queue[N];
void enQueue(int val){
    if((rear+1)%N==front){
        cout<<"Queue is full"<<endl;
    }else if(front==-1&&rear==-1){
        front=0;
        rear=0;
        Queue[rear]=val;
    }else{
        rear=(rear+1)%N;
        Queue[rear]=val;
    }
}
int Dequeue(){
    if(front==-1&&rear==-1){
        cout<<"Queue is empty"<<endl;
        return -1;
    }else if(rear==front){
        int temp = Queue[front];
        cout<<" Dequeue Element is "<<temp<<endl;
        front = rear = -1; // Reset queue to empty state
        return temp;
    }else{
        int temp = Queue[front];
        cout << "Dequeue Element is " << temp << endl;
        front = (front + 1) % N;
        return temp;
    }
}
void display(){
    if(front==-1&&rear==-1){
        cout<<"Queue is empty"<<endl;
    }else{
    for(int i=front;i<=rear;i=(i+1)%N){
                cout<<Queue[i]<<" ";
            }
    }
}
bool isFull(){
    return (rear+1)%N==front;
}
bool isEmpty(){
    return front==-1&&rear==-1;
}
int main(){
    int choice ,item;
    while(1){
        cout<<"\n 1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3.  Display Quesue"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<" \n Enter Choice ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<" Enter Element to enQueue ";
                cin>>item;
                enQueue(item);
                break;
            case 2:
            int deQueued;
                    deQueued=Dequeue();
                if(deQueued!=-1)
                cout<<deQueued<<" DeQueued ";
                break;
            case 3:
                cout<<" \n Queue is ";
                display();
                break;
            case 4:
                return 0;
                break;
            default:
            cout<<"Invalid Choice "<<endl;
        }
    }
}