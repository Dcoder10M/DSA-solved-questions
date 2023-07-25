
class Solution {
public:
    TreeNode* solve(vector<int>& pre,int p,int q,vector<int> in,int i,int j,map<int,int> &m){
        if(p>q || i>j)return NULL;
        TreeNode* root=new TreeNode(pre[p]);
        int pos=m[pre[p]];
        int numleft=pos-i;
        root->left=solve(pre,p+1,p+numleft,in,i,pos-1,m);
        root->right=solve(pre,p+1+numleft,q,in,pos+1,j,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m;
        for(int i=0;i<preorder.size();i++){
            m[inorder[i]]=i;
        }
        
        TreeNode* ans=solve(preorder,0,preorder.size()-1,inorder,0,preorder.size()-1,m);
        return ans;
    }
};