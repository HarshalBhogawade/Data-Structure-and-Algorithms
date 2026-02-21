#include<bits/stdc++.h>
using namespace std;
Node* Search(Node* root , int val){

    Node* temp = root;
    //search while temp != nullptr in case no val present ,
    //search while node->val not match to the search val
    //tc : O(logn) Sc : O(1)
    while(temp != nullptr && temp->val != val){
        temp = val < temp->val ? temp->left : temp->right;
    }
    return temp;
}
int main(){
    Node* find = Search(root, 10);
    console.log(find);
}