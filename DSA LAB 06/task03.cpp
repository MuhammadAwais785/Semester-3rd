#include<iostream>
using namespace std;
struct Node{
    string Title;
    string Author;
    string Edition;
    int Price;
    Node*next;
};
struct LinkedList{
    Node*head;
    LinkedList(){
        head=nullptr;
    }

    void Insert_front(string title,string author,string edition,int price){
        Node*newNode=new Node();
        newNode->Title=title;
        newNode->Author=author;
        newNode->Edition=edition;
        newNode->Price=price;
        newNode->next=head;
        head=newNode;
    }

void DeletePriceGreater() {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->Price > 2000) {
                if (current == head) {
                    head = head->next;
                    delete current;
                    current = head;
                } else {
                    previous->next = current->next;
                    // delete current;
                    current = current->next;
                }
            } else {
                previous = current;
                current = current->next;
            }
        }
    }


    void Display(){
        Node*temp=head;
        while(temp!=nullptr){
            cout<<" Title "<<temp->Title<<" "<<" \n Author "<<temp->Author<<" \n Edition "<<temp->Edition<<" \n Price "<<temp->Price<<"\n\n";
            temp=temp->next;
        }
    }
};

int main(){
    LinkedList list;
    list.Insert_front(" Title ", " Author "," Edition ", 500);
    list.Insert_front(" Title ", " Author "," Edition ", 2100);
    list.Insert_front(" Title ", " Author "," Edition ", 1600);
    list.Insert_front(" Title ", " Author "," Edition ", 2200);
    list.Insert_front(" Title ", " Author "," Edition ", 2300);
    list.DeletePriceGreater();
    list.Display();
}