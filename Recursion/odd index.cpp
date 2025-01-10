#include<iostream>
using namespace std;
void Index(int arr[], int index){
    if(index>10){
        return ;
    }
    if(index%2!=0){
        cout<<" Index "<<index<<" Value " <<arr[index]<<endl;
        Index(arr,index+2);
    }else{
        Index(arr,index+1);
    }
}
int main(){
    int arr[10]={1,1,3,4,5,7,7,8,9,10};
    Index(arr,0);
}