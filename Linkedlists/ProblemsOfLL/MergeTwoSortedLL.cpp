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

Node *mergeTwoLists(Node *headA, Node *headB)
{

    Node *t1 = headA;
    Node *t2 = headB;
    Node *Dummy = new Node(-1);
    Node *temp = Dummy;

    while (t1 != nullptr && t2 != nullptr)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if (t1 != nullptr)
        temp->next = t1;
    else
        temp->next = t2;
    return Dummy->next;
}

int main()
{
    vector<int> arr1 = {2,4,5,6};
    Node *headA = Converarrtoll(arr1);
    vector<int> arr2 = {1,2,5,6,7};
    Node* headB = Converarrtoll(arr2);
    Node *head = mergeTwoLists(headA , headB);
    print(head);
        // this problem is not implementable in vs code so pls perform in lc or gfg;
        // cout<<"Length of linked list : "<<lengthofll(head);
        // cout<<searchanelem(arr,k,head);
    return 0;
}