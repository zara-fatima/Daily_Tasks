#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    stack<char> st;
    string postfix;

    for (int i=0; i < infix.length(); i++) 
	{
		char ch=infix[i];
        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If '(' push to stack
        else if (ch == '(') {
            st.push(ch);
        }
        // If ')' pop until '('
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }
        // If operator
        else {
            int precCh;
            if (ch == '+' || ch == '-') precCh = 1;
            else if (ch == '*' || ch == '/') precCh = 2;
            else if (ch == '^') precCh = 3;
            else precCh = -1;

            while (!st.empty()) {
                int precTop;
                if (st.top() == '+' || st.top() == '-') precTop = 1;
                else if (st.top() == '*' || st.top() == '/') precTop = 2;
                else if (st.top() == '^') precTop = 3;
                else precTop = -1;

                // check precedence (for ^ we handle right-associativity)
                if ((precTop > precCh) || (precTop == precCh && ch != '^')) {
                    if (st.top() == '(') break;
                    postfix += st.top();
                    st.pop();
                }
                else break;
            }
            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
