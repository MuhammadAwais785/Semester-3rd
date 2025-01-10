#include<iostream>
using namespace std;
void Odd(int start, int end){
    if(start<=end){
        if(start%2!=0){
            cout<<start<<" ";
            Odd(start+2,end);
        }else{
            Odd(start+1,end);
        }
    }
}
int main(){
    int start,end;
    cin>>start;
    cin>>end;
    Odd(start,end);
}
