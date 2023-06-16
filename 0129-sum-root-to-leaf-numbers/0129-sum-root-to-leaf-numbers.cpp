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
    void solve(TreeNode* root,int temp,int &ans){
        if(!root)return;
        if(!root->left && !root->right){
            temp=temp*10+root->val;
            ans+=temp;
            return;
        }
        temp=temp*10+root->val;
        solve(root->left,temp,ans);
        solve(root->right,temp,ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        int temp=0;
        solve(root,temp,ans);
        return ans;
    }
};