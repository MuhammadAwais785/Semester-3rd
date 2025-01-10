#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<char> s;
    char input;
    cout<<" Enetr Character ";
    while(cin>>input&&input!='F'&&input!='f'){
        if(!s.empty()&&s.top()==input){
            s.pop();
        }else{
            s.push(input);
        }
    }
    string result="";
    while (!s.empty())
    {
        /* cresultode */
        result=s.top()+result;
        s.pop();
    }
    
    cout<<" Final result is "<<result;
    return 0;
}