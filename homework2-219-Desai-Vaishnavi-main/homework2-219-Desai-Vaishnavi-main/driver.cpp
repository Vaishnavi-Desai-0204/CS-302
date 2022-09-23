//driver.cpp
//main function 
//VAISHNAVI DESAI
//To execute infix to postfix functions

#include <iostream>
#include <string>
using namespace std;

#include "linkedstack.h"
int precedence(char c);
string InfixToPostfix(string s); 
void evaluate(string r);
 

int main(void) {
    string exp ;
    cout << "ENTER INFIX EXPRESSION:" << endl;
    cin >> exp;
    string result =InfixToPostfix(exp);    
    cout << "POSTFIX EXPRESSION :" << result <<endl;
    cout << "RESULT :" ;
    evaluate(result);
    return 0;
}

int precedence(char c) {
    if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
 
// The main function to convert infix expression to postfix expression
string InfixToPostfix(string s) {
 
    LinkedStack<char> st;
    string result;
    int i;
    char c;
    for(i = 0; i < s.length(); i++) {
         c = s[i];
 
        // If the scanned character is
        // an operand, add it to output string.
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            result += c;
        }
        //If an operator is scanned
        else {
            while(!st.isEmpty() && precedence(s[i]) <= precedence(st.peek())) {
                result += st.peek();
                st.pop(); 
            }
            st.push(c);
        }
    }
 
    // Pop all the remaining elements from the stack
    while(!st.isEmpty()) {
        result += st.peek();
        st.pop();
    }
    return result;
}

void evaluate(string r){   
    
     LinkedStack<float> t;
     
     float op1=0;
     float op2=0;
     float val=0;
     int i=0;
     char c;
    
    for (i = 0; i < r.length(); i++) {
        c = r[i];
        if (c >= '0' && c <= '9') {
           
        float newVal = (float)(c-'0');
            t.push(newVal);            
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {

           op1=t.peek(); //pulling out operands and performing respective operations
           t.pop();
           op2=t.peek();
           t.pop();

            switch (c) 
            {
            case '*':
                val = op2 * op1;
                break;

            case '/':
                val = op2 / op1;
                break;

            case '+':
                val = op2 + op1;
                break;

            case '-':
                val = op2 - op1;
                break;
            }

            // push the value obtained above onto the stack
            t.push(val);
        }
    }    
    cout << val<< endl;
}




   
