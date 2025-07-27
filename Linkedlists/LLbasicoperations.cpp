#include<iostream>
#include<vector>
#include<string>
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

//length of ll
int lengthofll(Node* head){
    int count =0;
    Node* temp = head;
    while(temp){
        count++;
        temp = temp->next;

    }
    return count;
}

//search an elem in ll
string searchanelem(vector<int>arr , int k , Node* head){
    if(head->data == k){
        return "Element is found";
    }

    Node* temp = head;
    while(temp){
        if(temp->data ==k){
            return "Element is found";
        }
        temp= temp->next;
    }

    return "Not found element";
}


int main(){
    vector<int>arr = {2,4,6,8};
    int k = 6;
    Node* head = Converarrtoll(arr);
    cout<<"Length of linked list : "<<lengthofll(head);
    cout<<searchanelem(arr,k,head);
    return 0;

}