#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};


int main(){
    //inserting only in tree , for printing the nodes value we have to use traversals 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);

    

}