#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node*previous;
};

struct Deck{
    Node*head;
    Node*tail;

    Deck(){
        head=nullptr;
        tail=nullptr;
    }

    void InsertFront(int val){
        Node*newNode = new Node;
        newNode->data = val;
        newNode->next=head;
        newNode->previous=nullptr;
        if(head==nullptr){
            head=tail=newNode;
        }else{
            head->previous=newNode;
            head=newNode;
        }
    }

    void InsertLast(int val){
        Node*newNode = new Node();
        newNode->data=val;
        newNode->next=nullptr;
        newNode->previous=tail;
        if (tail == nullptr) { 
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void InsertAtLocation(int value,int position){
        Node*newNode = new Node();
        newNode->data = value;
        if(position==1){
            InsertFront(value);
            return;
        }
        Node*temp=head;
        for(int i=1;i<position-1&&temp!=nullptr;i++){
            temp=temp->next;
        }
        if(temp==nullptr){
            cout<<" Position is out of bound ";
            return;
        }else{
            newNode->next=temp->next;
            newNode->previous=temp;
                if (temp->next != nullptr) { 
            temp->next->previous = newNode;
            } else { 
                tail = newNode;
            }
            temp->next=newNode;
        }
    }

    void deleteFront() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    head = head->next; 
    if (head != nullptr) { 
        head->previous = nullptr;
    } else { 
        tail = nullptr;
    }

    delete temp; 
    cout << "Front node deleted." << endl;
}

    void deleteLast() {
    if (tail == nullptr) { // If the list is empty
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = tail;
    tail = tail->previous; // Move tail to the previous node

    if (tail != nullptr) { // If the list still has nodes
        tail->next = nullptr; // Disconnect the old tail
    } else { // If the list is now empty
        head = nullptr;
    }

    delete temp; // Delete the old tail node
    cout << "Last node deleted." << endl;
}


    void Display(){
        Node*temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void deleteAtPosition(int position) {
    if (head == nullptr) { // Handle empty list
        cout << "List is empty" << endl;
        return;
    }

    if (position == 1) { // Handle deletion of the first node
        deleteFront();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) { // Position out of bounds
        cout << "Position out of bounds" << endl;
        return;
    }

    if (temp->next != nullptr) { // Update next node's previous pointer
        temp->next->previous = temp->previous;
    } else { // If deleting the last node, update the tail
        tail = temp->previous;
    }

    if (temp->previous != nullptr) { // Update previous node's next pointer
        temp->previous->next = temp->next;
    }

    delete temp; // Delete the node
    cout << "Node at position " << position << " deleted." << endl;
}


    void RDisplay(){
        if(tail==nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }else{
        cout<<"\n Reverse Loop \n";
        Node*temp=tail;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->previous;
            }
        cout<<endl;
        }
    }
};
int main(){
    Deck deck;
    deck.InsertFront(5);
    deck.InsertFront(6);
    deck.Display();
    deck.InsertLast(7);
    deck.InsertLast(8);
    deck.InsertLast(9);
    deck.Display();
    deck.InsertAtLocation(1,1);
    deck.InsertAtLocation(3,3);
    deck.Display();
    deck.RDisplay();
    deck.deleteFront();
    deck.Display();
    deck.RDisplay();
    deck.deleteLast();
    deck.Display();
}