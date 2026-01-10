    bool isSameTree(TreeNode* p, TreeNode* q) {
        // both nodes are null
        if (p == NULL && q == NULL)
            return true;

        // one is null, other is not
        if (p == NULL || q == NULL)
            return false;

        // values differ
        if (p->val != q->val)
            return false;

        // check left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }