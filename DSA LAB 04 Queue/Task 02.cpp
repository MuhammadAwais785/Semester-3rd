#include<iostream>
using namespace std;
#define N 5
int count=0;
class Queue
{
    string arr[N];
    int front, rear;
    public:
        Queue(){
            front = rear = -1;
        }

        bool IsFull(){
            return rear+1 == N;
        }

        bool IsEmpty(){
            return front == -1;
        }

        void EnQueue(string x){
            if(IsFull()){
                cout << "Queue is full\n";
            }else{
                    if (front == -1)  // When adding the first element
                    front = 0;
                rear++;
                arr[rear] = x;
            }
        }

        string DeQueue(){
            if(IsEmpty()){
                cout << "Queue is empty\n";
                return "";
            }else{
                string temp = arr[front++];
                count++;
                return temp;
            }
        }

        void Display(){
            if (IsEmpty()) {
                cout << "Queue is empty\n";
                } else {
                    for(int i=front;i<=rear;i++){
                        cout << arr[i] << " ";
                        
                    }
                }    
        }

        int Size() {
        if (IsEmpty()) {
            return 0;
        } else {
            return (rear+ 1);
        }
    }
};

int main(){
    Queue q;
    string arr[3][3]={
        {"Ali","2","200"}, 
        {"Awais","5","300"},
        {"Asad","8","900"},
    };
    
    while (true)
    {
        cout << "\n1. Add Customer" << endl;
        cout << "2. Delete Customer" << endl;
        cout << "3. Calculate Total Number Of Customers Served" << endl;
        cout << "4. Time Required to served remaining customer is " << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                string id;
                cout << "Enter Customer ID: ";
                cin >> id;
                bool found = false;
                for (int i = 0; i < 3; i++) {
                    if (arr[i][1] == id) {
                        q.EnQueue(arr[i][1]);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Customer ID not found\n";
                }
                break;
            }

            case 2:{
                string Dequed=q.DeQueue();
                cout<<" \nID "<<Dequed<<" Served and Dequeued \n\n";
                break;
                }

            case 3:{
                cout<<" Total Number of Customer served is "<<count;
                break;
                }
            
            case 4:{
                int remaining=q.Size();
                cout<<" Time required to serve remaining Customer is "<<5*remaining;
                break;
            }

            case 5:{
                q.Display();
                break;
            }

            case 6:{
                return 0;
            }

            default:{
                cout<<" Invalid Choice. try again!! ";
                break;
            }
        }
    }
}