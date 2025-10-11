#include<iostream>
#include<vector>

using namespace std;
class Node{
public:
    int data;
    Node* next;

        
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
//arratoll
Node* Converarrtoll(vector<int>arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;

}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node *getIntersectionNode(Node *headA, Node *headB) {
        Node* t1 = headA;
        Node* t2 = headB;

        // Traverse both lists
        // When a pointer reaches the end, move it to the start of the other list
        // If there is an intersection, they will meet there
        // If not, both will reach nullptr at the same time
        while(t1!=t2){
            if(t1==nullptr) t1 = headA;
            else t1 = t1->next;

            if(t2==nullptr) t2 = headB;
            else t2 = t2->next;

        }
        return t1;
    }
int main(){
    vector<int>arr1 = {5,6,1,8,4,5};
    Node* headA = Converarrtoll(arr1);
    vector<int>arr = {4,1,8,4,5};
    Node* headB = Converarrtoll(arr);
    Node* intersectn = getIntersectionNode(headA , headB);
    if(intersectn == nullptr) cout<<"No intersection";
    else cout<<"intersection";
    // this problem is not implementable in vs code so pls perform in lc or gfg;
    // cout<<"Length of linked list : "<<lengthofll(head);
    // cout<<searchanelem(arr,k,head);
    return 0;
}