class Solution {
public:
    int sum=0;
    void helper(TreeNode* root,TreeNode* parent,TreeNode* gp){
        if(root==NULL)return;
        if(gp && gp->val%2==0)sum+=root->val;
        helper(root->left,root,parent);
        helper(root->right,root,parent);
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)return 0;
        helper(root,NULL,NULL);
        return sum;
    }
};