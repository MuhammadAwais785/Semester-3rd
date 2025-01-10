#include<iostream>
using namespace std;
struct Node{
    string Title;
    string Author;
    int Price;
    Node*next;
};
struct LinkedList{
    Node*head;
    LinkedList(){
        head=nullptr;
    }

    void Push(string title,string author,int price){
        Node*newNode=new Node();
        newNode->Title=title;
        newNode->Author=author;
        newNode->Price=price;
        newNode->next=head;
        head=newNode;
    }

    void Pop(){
        if(head==nullptr){
            return;
        }else{
        Node*temp=head;
        head=head->next;
        delete temp;
        }
    }
    void Display(){
        if(head==nullptr){
            cout<< "\n Empty \n";
        }else{
        Node*temp=head;
        while(temp!=nullptr){
            cout<<" Title "<<temp->Title<<" "<<" \n Author "<<temp->Author<<" \n Price "<<temp->Price<<"\n\n";
            temp=temp->next;
            }
        }
    }
};

int main(){
    LinkedList list;
    int choice;
    string title;
    string author;
    int price;
    do{
        cout<<"1.Push\n2.Pop\n3.Display\n4.Exit\n";
        cout<<" Enter Choice ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<" \n Enter Title ";
            cin>>title;
            cout<<" \nEnter Author Name ";
            cin>>author;
            cout<<"\n Enter Price ";
            cin>>price;
            list.Push(title, author, price);
            break;
        case 2:
            list.Pop();
            cout<<"\n Poped Successfully ";
            break;
        case 3:
            list.Display();
            break;
        case 4:
            cout<<" \nExisted ";
            return 0;    
        default:
            cout<<" \n Invalid Entery \n";
            break;
        }
    }while(true);

    return 0;
}