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
    TreeNode* solve(vector<int>&nums,int i,int j){
        if(i>j)return NULL;
        int k=i;
        int mx=INT_MIN;
        for(int p=i;p<=j;p++){
            if(nums[p]>mx){
                mx=nums[p];
                k=p;
            }
        }
        TreeNode* temp=new TreeNode(nums[k]);
        temp->left=solve(nums,i,k-1);
        temp->right=solve(nums,k+1,j);
        return temp;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};