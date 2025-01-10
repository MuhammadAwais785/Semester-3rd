#include<iostream>
#include<stack>
#include<string>
#include<cmath> // Include this for pow() function

using namespace std;

void results(string s) {
    stack<int> st;
    for(int i = 0; i < s.length(); i++) {
        if(isdigit(s[i])) {
            st.push(s[i] - '0'); // Push the digit onto the stack
        } else {
            int op2 = st.top(); 
            st.pop();
            int op1 = st.top(); 
            st.pop();

            switch(s[i]) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '^':
                    st.push(pow(op1, op2)); // Correct exponentiation using pow()
                    break;
            }
        }
    }
    cout << "Result: " << st.top() << endl;
}

int main() {
    string s;
    cout << "Enter postfix expression: ";
    cin >> s;
    results(s);
    return 0;
}