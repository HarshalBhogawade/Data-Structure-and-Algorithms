#include <iostream>
#include <queue>
using namespace std;

class myStack {
    
    queue<int> q1, q2;

public:
    void push(int x) {
        
        // Push x first in empty q2
        q2.push(x);
        // Push all the remaining
        // elements in q1 to q2.
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // swap the names of two queues
        swap(q1, q2);
    }

    void pop()
    {
        // if no elements are there in q1
        if (q1.empty())
            return;
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    int size() { return q1.size(); }
};

// Driver code
int main() {
    myStack st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;

    cout << st.size() << endl;
    return 0;
}