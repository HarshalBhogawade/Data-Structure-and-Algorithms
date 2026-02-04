#include<bits/stdc++.h>
using namespace std;
bool getpath(Node* root , vector<int>&ans, int x){
    if(!root){
        return false;
    }

    arr.push_back(root->val);

    if(root->val == x){
        return true;
    }

    if(getpath(root->left , arr,x) || getpath(root->right, arr,x)){
        return true;
    }

    arr.pop_back();

    return false;
}
vector<int>solve(Node* a, int b){
    vector<int>arr;
    if(a==nullptr){
        return arr;
    }

    getpath(a,arr,b);
    return arr;
}

int main(){

}