#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
ALGORITHM: Infix to Postfix Conversion using Shunting Yard Algorithm
1. Initialize empty stack for operators and empty result string
2. Scan infix expression from left to right:
    a) If operand (letter/digit): add to result
    b) If '(': push to stack
    c) If ')': pop from stack to result until '(' found
    d) If operator: pop operators with higher/equal precedence, then push current operator
3. Pop all remaining operators from stack to result
4. Return postfix expression

Time Complexity: O(n), Space Complexity: O(n)
*/

// Function to return precedence of operators
int prec(char ch)
{
     if (ch == '^')
     {
          return 3;
     }
     else if (ch == '*' || ch == '/')
     {
          return 2;
     }
     else if (ch == '+' || ch == '-')
     {
          return 1;
     }
     else
     {
          return -1;
     }
}

// Function to check if operator is right associative
bool isrightassociate(char ch)
{ 
     return ch == '^';
}

// main function
string infixtopostfix(string &infix)
{
     stack<char> st; // Stack to store operators and parentheses
     string res;     // Result string to store postfix expression

     // Step 1 Scan infix expression from left to right
     for (int i = 0; i < infix.length(); i++)
     {
          char ch = infix[i];

          // Step 2: If character is operand (letter or digit), add to result
          if ((ch >= 'a' && ch <= 'z') ||
              (ch >= 'A' && ch <= 'Z') ||
              (ch >= '0' && ch <= '9'))
          {
               res += ch;
          }
          // Step 3: If character is '(', push to stack
          else if (ch == '(')
          {
               st.push(ch);
          }
          // Step 4: If character is ')', pop from stack until '(' is found
          else if (ch == ')')
          {
               while (!st.empty() && st.top() != '(')
               {
                    res += st.top();
                    st.pop();
               }
               if (!st.empty())
                    st.pop(); // Remove '(' from stack
          }
          // Step 5: If character is operator
          else
          {
               // Pop operators with higher or equal precedence (considering associativity)
               while (!st.empty() && st.top() != '(' &&
                      (prec(ch) < prec(st.top()) ||
                       (prec(st.top()) == prec(ch) && !isrightassociate(ch))))
               {
                    res += st.top();
                    st.pop();
               }
               st.push(ch); // Push current operator to stack
          }
     }

     // Step 6: Pop all remaining operators from stack
     while (!st.empty())
     {
          res += st.top();
          st.pop();
     }

     return res;
}

int main()
{
     string infix = "((A+B)*(C-D))/E";
     string postfix = infixtopostfix(infix);
     cout << "Postfix: " << postfix << endl;
     return 0;
}
