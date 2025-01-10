#include<iostream>
using namespace std;
struct Node{
    int orderID;
    string customerName;
    string address;
    int numberOfItems;
    double payment;
    Node* next;
};
struct Queue{
    Node*front;
    Node*rear;

    Queue(){
        front = rear = nullptr;
    }

    void EnQueue(int id,string name, string addr, int items, double pay){
        Node*newNode=new Node();
        newNode->orderID=id;
        newNode->customerName=name;
        newNode->address=addr;
        newNode->numberOfItems=items;
        newNode->payment=pay;
        newNode->next=nullptr;
        if(front==nullptr){
            rear=front=newNode;
        }else{
            Node*temp=rear;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    
    void DeQueue(){
        if(front==nullptr){
            return;
        }else{
            Node*temp=front;
            front=front->next;
            delete temp;
        }
    }

    void displayOrders() {
        if (front == nullptr) {
            cout << "No orders.\n";
            return;
        }
        Node* temp = front;
        cout << "\n Orders:\n";
        while (temp != nullptr) {
            cout << "Order ID: " << temp->orderID
                << "\nCustomer Name: " << temp->customerName
                << "\nAddress: " << temp->address
                << "\nNumber of Items: " << temp->numberOfItems
                << "\nPayment: " << temp->payment << "\n\n";
            temp = temp->next;
        }
    }
};

int main(){
    Queue queue;
    int choice;
    string name, address;
    int items,id;
    double payment;

    do {
        cout << "1. Add Order\n2. Delete Order \n3. Display Orders\n4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Customer Name: ";
                cin >> name;
                cout << "Enter Address: ";
                cin >> address;
                cout << "Enter Number of Items: ";
                cin >> items;
                cout << "Enter Payment: ";
                cin >> payment;
                cout<<" Order ID ";
                cin>>id;
                queue.EnQueue(id,name, address, items, payment);
                break;
            case 2:
                cout<<"\n DeQueued \n";
                queue.DeQueue();
                break;
            case 3:
                queue.displayOrders();
                break;
            case 4:
                cout << "\nExiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (true);

    return 0;
}