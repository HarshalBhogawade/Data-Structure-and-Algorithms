#include<iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;
        Node(int data1){
            data = data1;
            next  = nullptr;
            back = nullptr;
        }
    
        Node(int data1 , Node* next1 , Node* back1){
            data = data1;
            next  = next1;
            back = back1;
        }
};

Node* ConvertarrtoDll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr , prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head=head->next;
    } 
}

void ReverseDll(Node* head){
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    // temp now points to the last node
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->back;
    }
    cout << endl;
}

int main(){
    vector<int> arr = {12,2,6,9,10,14};
    Node* head = ConvertarrtoDll(arr);
    ReverseDll(head);
    print(head);
}