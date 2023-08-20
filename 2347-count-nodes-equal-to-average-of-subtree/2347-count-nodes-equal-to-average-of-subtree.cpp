class Solution {
public:
    int s(TreeNode* root,int &v){
        if(root==NULL)return 0;
        v++;
        return root->val + s(root->right,v) + s(root->left,v);
    }
    int ct=0;
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL)return 0;
        int v=0;
        int x = s(root,v);
        if(root->val == (x/v))ct++;
        averageOfSubtree(root->right);
        averageOfSubtree(root->left);
        return ct;
    }
};