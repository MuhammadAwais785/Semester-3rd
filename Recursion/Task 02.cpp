#include<iostream>
using namespace std;
bool IsPrime(int x,int i){
    //recursive function to check prime number
    if(x==2){
        return (x==2);
    }
    if(x%i==0){
        return false;
    }
    if(i*i>x){
        return true;
    }
    return IsPrime(x,i+1);
}
int main(){
    int num ,i;
    i=2;
    cout<<" Enter Number ";
    cin>>num;
    if(IsPrime(num,i)){
        cout<<" Number is Prime ";
    }else{
        cout<<" Not Prime ";
    }
}