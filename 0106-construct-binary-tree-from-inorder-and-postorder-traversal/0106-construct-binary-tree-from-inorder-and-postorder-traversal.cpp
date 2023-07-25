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
    int find(vector<int> &in,int val){
        for(int i=0;i<in.size();i++){
            if(in[i]==val)return i;
        }return -1;
    }
    TreeNode* solve(vector<int>& inorder,int start,int end, vector<int>& postorder,int &ind){
        if(ind<0 || start>end)return NULL;
        TreeNode* root=new TreeNode(postorder[ind]);
        int pos=find(inorder,postorder[ind]);
        ind--;
        root->right=solve(inorder,pos+1,end,postorder,ind);
        root->left=solve(inorder,start,pos-1,postorder,ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)   {
        int ind=inorder.size()-1;
        TreeNode* ans=solve(inorder,0,inorder.size()-1,postorder,ind);
        return ans;
    }
};