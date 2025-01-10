#include<iostream>
using namespace std;
bool Prime(int start){
    for(int i=2;i<start/2;i++){
        if(start%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    bool result=Prime(2);
    if(result){
        cout<<" Number is prime ";
    }else{
        cout<<" Number is not prime ";
    }
}