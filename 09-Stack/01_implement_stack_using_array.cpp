#include <bits/stdc++.h>
using namespace std;

// operations to implement
/*1 isempty
2- is full
3-push
4-pop
5-top

Timr complexity O(1) for every operation
*/

// fixed sized array
class stacks
{
public:
    int *arr;
    int capacity;
    int top;

    stacks(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    // Pushes an element onto the stack
    void push(int num)
    {
        if (top == capacity - 1)
        {
            cout << "Stack is overflow";
            return;
        }
        arr[++top] = num;
    }

    // Removes and returns the top element of the stack
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is underflow";
            return -1;
        }
        return arr[top--];
    }

    // Checks if the stack is full
    bool isfull()
    {
        return top == capacity - 1;
    }

    // Checks if the stack is empty
    
    bool isempty()
    {
        return top == -1;
    }

    // Returns the top element of the stack without removing it
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is underflow";
            return -1;
        }
        return arr[top];
    }
};

// dynamic sized array;
class stack2
{
public:
    int top = -1;
    vector<int> st;
    void push(int x)
    {
        st.push_back(x);
        top++;
    }

    int pop()
    {
        return st[top--];
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is underflow";
            return -1;
        }
        else
        {
            return st[top];
        }
    }

    bool isempty()
    {
        return top == -1;
    }
};
int main()
{
    stacks st(4);
    st.push(4);
    st.push(3);
    st.push(5);
    st.push(1);
    cout << "Is stack full" << st.isfull() << endl;
    cout << "top element : " << st.peek() << endl;

    stack2 st1;
    st1.push(12);
    cout << "Top element is : " << st1.peek() << endl;
}
