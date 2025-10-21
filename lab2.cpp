// QUESTION  1.	Write a program to take numbers from user and stored into stack. Pop the values from  stack and show only even values on screen and show highest marks on the screen.



#include <iostream>
#include <stack>
using namespace std;
int main() {
stack<int> st;
int n, val;
cout << "Enter number of elements: ";
cin >> n;
cout << "Enter " << n << " numbers: ";
for (int i = 0; i < n; i++) {
cin >> val;
st.push(val);
}
int highest = st.top();
cout << "Even numbers: ";
while (!st.empty()) {
int topVal = st.top();
st.pop();
if (topVal % 2 == 0) {
cout << topVal << " ";
}
if (topVal > highest) {
highest = topVal;
}
}
cout << "\nHighest mark: " << highest << endl;
return 0;
} 







//QUESTION 2. Write a program to input an infix expression into a string variable. Convert the expression into post-fix notation by using a stack.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string result = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            result += c;  
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();  
        }
        else {  
            while (!st.empty() && priority(st.top()) >= priority(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;

    cout << "Postfix expression: " << infixToPostfix(exp) << endl;
    return 0;
}
