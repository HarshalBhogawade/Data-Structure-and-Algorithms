// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(n) in worst case when all characters are opening brackets
#include<iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char ch : s) {
            // Push opening brackets onto the stack
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if(st.empty()) return false;
                
                // Check if current closing bracket matches the top opening bracket
                if((ch == ')' && st.top() == '(') || 
                   (ch == '}' && st.top() == '{') || 
                   (ch == ']' && st.top() == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
int main() {
    Solution solution;
    string test = "()[]{}";
    
    if(solution.isValid(test)) {
        cout << "Valid parentheses" << endl;
    } else {
        cout << "Invalid parentheses" << endl;
    }
    
    return 0;
}