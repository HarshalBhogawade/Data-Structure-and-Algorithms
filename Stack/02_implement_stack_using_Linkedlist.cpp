#include <bits/stdc++.h>
using namespace std;

// complexity for every operation is O(1)

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class mystack
{
    Node *top;
    int cnt = 0;

public:
    mystack()
    {
        top = nullptr;
    }

    // push(x): TC = O(1), SC = O(1)
    void push(int x)
    {
        cnt++;
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
    }

    // pop(): TC = O(1), SC = O(1)
    int pop()
    {
        if (top == nullptr)
            return -1;
        cnt--;
        Node *temp = top;
        top = top->next;
        int val = temp->data;
        delete temp;
        return val;
    }

    // isempty(): TC = O(1), SC = O(1)
    bool isempty()
    {
        return top == nullptr;
    }

    // peek(): TC = O(1), SC = O(1)
    int peek()
    {
        if (top == nullptr)
            return -1;
        return top->data;
    }

    // size(): TC = O(1), SC = O(1)
    int size()
    {
        if (top == nullptr)
            return -1;
        return cnt;
    }
};
int main()
{
    mystack st;
    st.push(1);
    st.push(2);
    st.push(4);
    st.pop();
    cout << "Stack size : " << st.size() << endl;
    cout << "IS empty : " << st.isempty() << endl;
    cout << "element on top of stack : " << st.peek() << endl;
}