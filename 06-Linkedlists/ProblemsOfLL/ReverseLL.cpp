#include <iostream>
#include <vector>

using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
// arratoll
Node *Converarrtoll(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverseList(struct Node *head)
{
    // code here
    // Node* temp = head;
    // stack<int>st;
    // while(temp){
    //     st.push(temp->data);
    //     temp = temp->next;
    // }
    // temp = head;
    // while(temp){
    //     temp->data = st.top();
    //     st.pop();
    //     temp = temp->next;
    // }

    // return head;
    Node *curr = head;
    Node *prev = nullptr;
    while (curr != nullptr)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 7};
    int k = 6;
    Node *head = Converarrtoll(arr);
    print(head);
    head = reverseList(head);
    print(head);

    // cout<<"Length of linked list : "<<lengthofll(head);
    // cout<<searchanelem(arr,k,head);
    return 0;
}