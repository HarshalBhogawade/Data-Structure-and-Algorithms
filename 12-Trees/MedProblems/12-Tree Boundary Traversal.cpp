#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

    vector<int>ans;
    
    //is leaf node function 
    bool isleaf(Node* node){
        return node && !node->left && !node->right;
    }
    
    
    
    //left boundry traversal
    void addleft(Node* root){
        if(!root) return;
        Node* curr = root->left;
        while(curr){
            if(!isleaf(curr)){
            ans.push_back(curr->data);
            }
            curr = curr->left ? curr->left : curr->right;

        }
        
    }
    
    //leaf traversal
    void addleaf(Node* root){
        if(!root) return;
        if(isleaf(root)){
            ans.push_back(root->data);
            return;
        }
        addleaf(root->left);
        addleaf(root->right);
    }
    
    //right boundry traversal
    void addright(Node* root){
        if(!root) return;
        vector<int>temp;
        Node* curr = root->right;
        while(curr){
           if(!isleaf(curr)){
                temp.push_back(curr->data);
            }
            curr = curr->right ? curr->right : curr->left;
        }
        for(int i = temp.size()-1 ; i>=0; i--){
            ans.push_back(temp[i]);
        }
    
    }

    vector<int> boundaryTraversal(Node* root) {
        // code here
        if(!root) return ans;
        if(!isleaf(root)){
            ans.push_back(root->data);
        }
        //traverse the left boundry
        addleft(root);
        //traverse the leaf nodes
        addleaf(root);
        //traverse the right boundry
        addright(root);
        return ans;
        
    }
int main(){

}