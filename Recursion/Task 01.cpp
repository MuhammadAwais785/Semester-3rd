#include<iostream>
using namespace std;
void PrintNumber(int arr[],int size){
    if(size<=10){
        cout<<arr[size]<<" ";
        PrintNumber(arr,size+1);
    }else{
        return;
    }
}
int  main(){
    int arr[11]={1,2,3,4,5,6,7,8,9,10,11};
    PrintNumber(arr,0);
}