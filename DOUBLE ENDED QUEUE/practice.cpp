// #include<iostream>
// using namespace std;
// struct Node{
//     int data;
//     Node*next;
//     Node*previous;
// };

// struct Deck{
//     Node*head;
//     Node*tail;

//     Deck(){
//         head = nullptr;
//         tail = nullptr;
//     }

//     void InsertFront(int val){
//         Node* newNode = new Node();
//         newNode->data=val;
//         newNode->next=head;
//         newNode->previous=nullptr;
//         if(head==nullptr){
//             head=tail = newNode;
//         }else{
//             head->previous=newNode;
//             head=newNode;
//         }
//     }

//     void InsertLast(int val){
//         Node* newNode = new Node();
//         newNode->data=val;
//         newNode->next=nullptr;
//         newNode->previous=tail;
//         if(head==nullptr){
//             head=tail = newNode;
//         }else{
//             tail->next=newNode;
//             tail = newNode;
//         }
//     }

//     void deleteFront(){
//         if(head==nullptr){
//             cout<<"List is empty"<<endl;
//             return;
//     }else{
//         Node* temp = head;
//         head=head->next;
//         head->previous=nullptr;
//         delete temp;
//         }
//     }

//     void deleteLast(){
//         if(tail==nullptr){
//             cout<<"List is empty"<<endl;
//             return;
//     }else{
//         Node* temp = tail;
//         tail=tail->previous;
//         tail->next=nullptr;
//         delete temp;
//         }
//     }

//     void Display(){
//         if(tail==nullptr){
//             cout<<"List is empty"<<endl;
//             return;
//         }else{
//         Node* temp = tail;
//         while(temp!=nullptr){
//             cout<<temp->data<<" ";
//             temp=temp->previous;
//             cout<<temp<<" deleted "<<endl;
//             }
            
//             cout<<endl;
//         }
//     }
// };

// int main(){
//     Deck q;
//     q.InsertLast(1);
//     // q.InsertLast(2);
//     // q.InsertLast(3);
//     q.Display();
//     q.deleteFront();
//     q.Display();
//     q.deleteLast();
//     q.Display();
// }
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node*previous;
};
struct List{
    Node*head;
    Node*tail;
    List(){
        head = nullptr;
        tail = nullptr;
    }

    void InsertFront(int x){
        Node*newNode=new Node();
        newNode->data=x;
        newNode->next=head;
        newNode->previous=nullptr;
        if(head==nullptr){
            head=tail=newNode;
        }else{
            head->previous=newNode;
            head=newNode;
        }
    }

    void InsertLast(int x){
        Node*newNode=new Node();
        newNode->data=x;
        newNode->next=nullptr;
        newNode->previous=tail;
        if(head==nullptr){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void InsertLocation(int x,int pos){
        Node*newNode=new Node();
        newNode->data=x;
        newNode->next=nullptr;
        newNode->previous=nullptr;

        if(pos==1){
            InsertFront(x);
            return;
        }

        Node*temp=head;
        for(int i=1;i<pos-1&&temp->next!=nullptr;i++){
            temp=temp->next;
        }

        if(temp==nullptr){
            cout<<" Position not found ";
            return;
        }else{
            newNode->next=temp->next;
            newNode->previous=temp;
            if(temp->next!=nullptr){
                temp->next->previous=newNode;
            }else{
                tail=newNode;
            }
            temp->next=newNode;
        }
    }

    void Display(){
        if(head==nullptr){
            cout<<" Empty ";
            return;
        }else{
            Node*temp=head;
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};
int main(){
    List l;
    l.InsertFront(5);
    l.InsertLast(7);
    l.InsertLocation(1,2);
    l.Display();
}