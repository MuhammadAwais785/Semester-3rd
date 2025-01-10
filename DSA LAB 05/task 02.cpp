#include<iostream>
using namespace std;
#define maxsize 5
class Priority{
    private:
    string Name[maxsize];
    int Age[maxsize];
    string CNIC[maxsize];
    int size;

    public:
        Priority(){
            size = 0;
        }

        void EnQueue(string  name , string cnic , int age){
            if(size>=maxsize){
                cout<<"Queue is full"<<endl;
            }else{
                Name[size] = name;
                CNIC[size] = cnic;
                Age[size]=age;
                size++;
            }
        }

        void DeQueue(){
            if(size==0){
                cout<<"Queue is empty"<<endl;
                return;
            }
                int max=0;
                for(int i=1;i<size;i++){
                    if(Age[i]>Age[max]){
                        max=i;
                    }
                }
                cout<<"\n\n Dequed  Name"<<Name[max]<<" With CNIC"<<CNIC[max]<<" With Age "<<Age[max]<<"\n\n"<<endl;
                
                for(int i=max;i<size-1;i++){
                    Name[i]=Name[i+1];
                    Age[i]=Age[i+1];
                    CNIC[i]=CNIC[i+1];
                }
                size--;
        }

        void Display(){
            if(size==0){
                cout<<" Queue is Empty ";
                return;
            }else{
                cout<<" Queue is "<<endl;
                for(int i=0;i<size;i++){
                    cout<<Name[i]<<" With CNIC "<<CNIC[i]<<"  Age "<<Age[i]<<endl;
                    }
            }
        }
};

int main(){
    Priority pq;
    pq.EnQueue(" Awais","82-828882882-1",18);
    pq.EnQueue(" Adeel","82-828882882-2",20);
    pq.EnQueue(" Ali","82-828882882-3",22);
    pq.EnQueue(" Asad","82-828882882-4",24);
    pq.EnQueue(" Umer","82-828882882-5",16);
    pq.Display();
    pq.DeQueue();
    pq.Display();
}