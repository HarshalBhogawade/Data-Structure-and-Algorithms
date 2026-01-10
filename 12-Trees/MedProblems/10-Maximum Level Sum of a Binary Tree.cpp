#include<bits/stdc++.h>
using namespace std;
int maximumLevel(Node* root){
    vector<int>ans;
    queue<Node*>q;
    
    if(root==nullptr) return 0;

    q.push(root);

    while(!q.empty()){
        int levelsize = q.size();
        int sum  =0;

        //process all nodes at current level
        for(int i=0;i<levelsize();i++){
            Node* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

            sum += node->val;
        }

        ans.push_back(sum);
        
    }

    //getting maximum sum level
    int level = 0;
    int maxsum = INT_MIN;
    for(int i=0;i<ans.size();i++){
        if(maxsum<ans[i]){
            maxsum = ans[i];
            level = i+1;
        }
    }
}
int main(){

}