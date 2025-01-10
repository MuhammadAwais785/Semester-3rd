#include<iostream>
#include<string>
using namespace std;
bool Plindrome(string str){
    int start=0;
    int end=str.length()-1;
    while(start<end){
        if(str[start]!=str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int main(){
    string str;
    cout<<" Enetr string ";
    cin>>str;
    if(Plindrome(str)){
        cout<<" It is Plindrome ";
    }else{
        cout<<" Not plindrome ";
    }
}