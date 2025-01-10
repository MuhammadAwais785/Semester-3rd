#include<iostream>
using namespace std;
void Prime(int start){
    
    bool found=true;
    for(int i=2;i<15/2;i++){
        if(start==2){
            found=true;
        }
        if(start==3){
            found=true;
        }
        if(start==5){
        found=true;
        }
        if(start%i==0){
            found=false;
        }
    }
        if(found){
            cout<<start<<" ";
        }
    
}
int main(){
    for(int i=2;i<20;i++){
        Prime(i);
    }
}