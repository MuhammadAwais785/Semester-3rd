#include<iostream>
using namespace std;
int recursion(int n){
    if(n<9)
        recursion(n+1);
    cout<<n<<" ";
    return 0;
}
int main(){
    recursion(0);
}