#include <iostream>
#include <stack>
using namespace std;

// Insert element into sorted stack
void sortedInsert(stack<int> &st, int x) {

    // If stack is empty or
    // top element is smaller, push x
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();
    
    // Recursively insert x in sorted order
    sortedInsert(st, x);

    st.push(top);
}

// Sort the stack recursively
void sortStack(stack<int> &st) {
    if (st.empty()) return;

    int top = st.top();
    st.pop();

    // Recursively sort the remaining stack
    sortStack(st);

    sortedInsert(st, top);
}

int main() {
    stack<int> st;
    st.push(41);
    st.push(3);
    st.push(32);
    st.push(2);
    st.push(11);

    sortStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}