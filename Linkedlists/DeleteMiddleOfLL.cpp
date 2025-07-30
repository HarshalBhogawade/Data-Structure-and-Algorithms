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

Node* deleteMiddle(Node* head) {
        if(!head) return nullptr;
        if(!head->next){ 
            delete head;
            return nullptr;
        }
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;
        while(fast!= nullptr && fast->next!=nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        slow->next = nullptr;
        delete slow;
        return head;
}



int main(){
    vector<int>arr = {2,4,6,8,7};
    int k = 6;
    Node* head = Converarrtoll(arr);
    print(head);
    head = deleteMiddle(head);
    print(head);

    // cout<<"Length of linked list : "<<lengthofll(head);
    // cout<<searchanelem(arr,k,head);
    return 0;

}