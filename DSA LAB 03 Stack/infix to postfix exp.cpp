#include<iostream>
#include<stack>
using namespace std;
int precedence(char p){
    if(p=='+' || p=='-')
    return 1;
    else if(p=='*' || p=='/')
    return 2;
    else if(p=='^')
    return 3;
    else
    return -1;
}
string infixToPostfix(string s){
    stack<char> st;
    string postFix = "";
    for(int i=0;i<s.length();i++){
        if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'){
            postFix+=s[i];
        }else if(s[i]=='('){
            st.push(s[i]);
        }else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                postFix+=st.top();
                st.pop();
            }
            if(!st.empty() && st.top()=='('){
                st.pop();
                }
        }else{
            while(!st.empty() && precedence(s[i])<=precedence(st.top())){
                postFix+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        postFix+=st.top();
        st.pop();
    }
    return postFix;
}
int main(){
    string s;
    cout<<"Enter the infix expression: ";
    cin>>s;
    string result=infixToPostfix(s);
    cout<<result;
}