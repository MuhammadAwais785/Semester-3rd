#include<iostream>
#define N 2
using namespace std;
class Queue{
    int arr[N];
    int rear;
    int front;

    public:
        
        Queue(){
            front=-1;
            rear=-1;
        }

        ~Queue(){
            delete [] arr;
        }

        bool IsEmpty(){
            return rear==-1;
        }

        bool IsFull(){
            return rear+1==N;
        }

        void EnQueue(int x){
            if(!IsFull()){
                rear=rear+1;
                arr[rear]=x;
            }else{
                cout<<" Queue OverFlow ";
            }
        }

        int DeQueue(){
            if(!IsEmpty()){
                front++;
                int temp=arr[front];
                return temp;
            }else{
                cout<<" Queue is Full ";
                return -1;
            }
        }

        void Display(){
            if(IsEmpty()){
                cout<<" Queue is Empty ";
            }else{
                for(int i=0;i<=rear;i++){
                    cout<<arr[i]<<" ";
                }
            }
        }
};
int main(void){
    Queue q;
    q.EnQueue(5);
    q.EnQueue(6);
    q.Display();
    q.EnQueue(7);
}