#include<bits/stdc++.h>
using namespace std;
/*Predecessor (largest < key)
while(node):
    if node->val > key
        move left

    else if node->val < key
        candidate = node
        move right

    else   // node == key
        go to left subtree
        take rightmost node
        stop
Successor (smallest > key)
while(node):
    if node->val < key
        move right

    else if node->val > key
        candidate = node
        move left

    else   // node == key
        go to right subtree
        take leftmost node
        stop
*/ 
vector<Node*> findPreSuc(Node* root, int key) {

    vector<Node*> ansvec;     // result → [predecessor, successor]

    Node* ans = NULL;         // will store predecessor
    Node* temp = root;        // traversal pointer


    // ---------- FIND PREDECESSOR ----------
    // predecessor = largest value < key

    while(temp){

        if(temp->data < key){
            // current node is a valid smaller candidate
            ans = temp;

            // try to find a closer (larger) smaller value
            temp = temp->right;
        }

        else if(temp->data > key){
            // too large → predecessor must be in left subtree
            temp = temp->left;
        }

        else{
            // key found
            // predecessor may be in left subtree
            // → rightmost node of left subtree
            Node* t = temp->left;

            while(t){
                ans = t;
                t = t->right;
            }
            break;
        }
    }

    ansvec.push_back(ans);   // store predecessor



    // ---------- FIND SUCCESSOR ----------
    // successor = smallest value > key

    ans = NULL;              // reset
    temp = root;

    while(temp){

        if(temp->data > key){
            // current node is a valid greater candidate
            ans = temp;

            // try to find a smaller greater value
            temp = temp->left;
        }

        else if(temp->data < key){
            // too small → successor must be in right subtree
            temp = temp->right;
        }

        else{
            // key found
            // successor may be in right subtree
            // → leftmost node of right subtree
            Node* t = temp->right;

            while(t){
                ans = t;
                t = t->left;
            }
            break;
        }
    }

    ansvec.push_back(ans);   // store successor

    return ansvec;
}
int main(){

}