#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
};
struct LinkedList{
    Node*head;
    LinkedList(){
        head=nullptr;
    }

    void Insert_front(int value){
        if(Size()<=10){
        Node*newNode=new Node();
        newNode->data=value;
        newNode->next=head;
        head=newNode;
        }else{
            cout<<" \n Size OverFlow . does not insert at First. \n ";
        }
    }

    void Insert_Last(int value){
        if(Size()<=10){
        Node*newNode=new Node();
        newNode->data=value;
        newNode->next=nullptr;
        if(head==nullptr){
            head=newNode;
        }else{
            Node*temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        }else{
            cout<<" \n Size OverFlow  does not insert at last. \n ";
        }
    }

    void InsertAtLocation(int value,int pos){
        Node*newNode=new Node();
        newNode->data=value;
        if(Size()<=10){
        if(pos==0){
            newNode->next=head;
            head=newNode;
        }
        Node*temp=head;
        for(int i=1;i<pos-1&&temp!=nullptr;i++){
            temp=temp->next;
        }

        if(temp==nullptr){
            cout<<" Position is out of bound . Insert At last ";
            Insert_Last(value);
        }else{
            newNode->next=temp->next;
            temp->next=newNode;
        }
        }else{ 
            cout<<" \n Size OverFlow does not insert at location \n ";
        }
    }

    int DeleteFront(){
        if(head==nullptr){
            return -1;
        }else{
        Node*temp=head;
        int deleted=temp->data;
        head=head->next;
        delete temp;
        return deleted;
        }
    }

    int DeleteLast(){
        if(head==nullptr){
            return -1;
        }
        if(head->next==nullptr){
            int deleted=head->data;
            delete head;
            head=nullptr;
            return deleted;
        }else{
        Node*temp=head;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        int deleted=temp->next->data;
        delete temp->next;
        temp->next=nullptr;
        return deleted;
        }
    }

    int DeleteAtLocation(int pos){
        if(head==nullptr){
            return -1;
        }

        if(pos==1){
            int deleted=head->data;
            Node*temp=head;
            head=head->next;
            delete temp;
            return deleted;
        }
        Node*temp=head;
        for(int i=1;i<pos-1&&temp!=nullptr;i++){
            temp=temp->next;
        }
        if(temp==nullptr){
            cout<<" Position is out of bound .";
            return -1;
        }else{
            Node* NodeToDeleted=temp->next;
            int deleted=NodeToDeleted->data;
            temp->next=NodeToDeleted->next;
            delete NodeToDeleted;
            NodeToDeleted->next=nullptr;
            return deleted;
        }
    }

    int Size(){
        Node*temp=head;
        int size=0;
        while(temp!=nullptr){
            temp=temp->next;
            size++;
        }
        return size;
    }

    void Display(){
        Node*temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<" NULL ";
    }
};

int main(){
    LinkedList list;
    list.Insert_front(1);
    list.Insert_front(2);
    list.Insert_front(3);
    list.Insert_Last(6);
    list.InsertAtLocation(2,1);
    list.DeleteFront();
    list.DeleteLast();
    list.DeleteAtLocation(2);
    list.Display();
    int listSize=list.Size();
    cout<<" \n List size is "<<listSize;
}