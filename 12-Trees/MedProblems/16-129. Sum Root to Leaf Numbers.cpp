    int totalsum = 0;
    void sum(TreeNode* root, int ans){
        if(!root) return;
        ans = (ans*10)+root->val; //build num from path vals
        
        if(root->left==nullptr && root->right==nullptr){
            totalsum += ans; //when reached leaf add to ttal sm
        }
        sum(root->left,ans);
        sum(root->right , ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        sum(root,ans);
        return totalsum;
    }