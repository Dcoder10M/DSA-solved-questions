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
    TreeNode* solve(vector<int> &pre,int p,int q,vector<int> &in,int i,int j,map<int,int> &m){
        if(p>q || i>j)return NULL;
        TreeNode* root=new TreeNode(pre[p]);
        int pos=m[pre[p]];
        int leftnode=pos-i;
        root->left=solve(pre,p+1,p+leftnode,in,i,pos-1,m);
        root->right=solve(pre,p+leftnode+1,q,in,pos+1,j,m);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        for(auto i:preorder){
            inorder.push_back(i);
        }
        sort(inorder.begin(),inorder.end());
        int n=preorder.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        TreeNode* ans=solve(preorder,0,n-1,inorder,0,n-1,m);
        return ans;
    }
};