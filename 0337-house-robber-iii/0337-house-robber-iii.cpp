/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,int> m;
    int rob(TreeNode* root) {
        if(!root)return 0;
        if(m.find(root)!=m.end())return m[root];
        int ans=0;
        ans=root->val;
        int temp=0;
        if(root->left!=NULL)temp=rob(root->left->left)+rob(root->left->right);
        if(root->right!=NULL)temp=temp+rob(root->right->left)+rob(root->right->right);
        ans+=temp;
        int ans2=rob(root->left)+rob(root->right);
        return m[root]=max(ans,ans2);
    }
};