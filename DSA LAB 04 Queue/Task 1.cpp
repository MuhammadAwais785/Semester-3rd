#include<iostream>
#define N 5
using namespace std;
class Vehicle{
    int arr[N];
    int rear;
    int front;

    public:
        
        Vehicle(){
            front=0;
            rear=-1;
        }

        ~Vehicle(){
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
                cout<<" Parking OverFlow ";
            }
        }

        int DeQueue(){
            if(!IsEmpty()){
                cout<<" \n DeQueue Element is ";
                cout<<arr[front];
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
                for(int j=front;j<=rear;j++){
                    cout<<arr[j]<<" ";
                }
            }
        }

        int index(int x){
            for(int i=0;i<N;i++){
                if(arr[i]==x){
                    return i;
                    }
                }
        }
};
int main(void){
    Vehicle q;
    q.EnQueue(5);
    q.EnQueue(6);
    q.EnQueue(7);
    cout<<" Enter Value to DeQueue ";
    int value;
    cin>>value;
    for(int i=0;i<=q.index(value);i++){
        q.DeQueue();
    }
    cout<<endl;
    cout<<" Remaining element in Queue is ";
    q.Display();
}