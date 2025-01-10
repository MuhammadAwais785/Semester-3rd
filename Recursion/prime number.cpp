#include<iostream>
using namespace std;
bool Prime(int num, int i=2){
    if(num<=2){
        return (num==2);
    }
    if(num%i==0){
        return false;
    }
    if(i*i>num){
        return true;
    }
    return Prime(num,i+1);
}
void prime(int start,int end){
    if(start>end){
        return;
    }
    if(Prime(start)){
        cout<<start<<" ";
    }
    prime(start+1,end);
}
int main(){
    int start,end;
    cout<<" Enter starting number ";
    cin>>start;
    cout<<" Enter Ending Number ";
    cin>>end;
    prime(start , end);
}