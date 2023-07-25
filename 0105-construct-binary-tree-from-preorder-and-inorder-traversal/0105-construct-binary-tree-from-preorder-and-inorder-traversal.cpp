class Solution {
public:
    int findPosition(vector<int> inorder, int element, int n){
        for(int i=0;i<n;i++){
            if(inorder[i]==element)
            return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int> inorder, vector<int> preorder, int &index, int inorderStart, int inorderEnd, int n){
        if(index>=n || inorderStart > inorderEnd){
            return NULL;
        }
        int element=preorder[index];
        TreeNode* root=new TreeNode(element);
        int position=findPosition(inorder, element, n);
        index++;
        root->left=solve(inorder, preorder, index, inorderStart, position-1, n);
        root->right=solve(inorder, preorder, index, position+1, inorderEnd, n);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int preorderIndex=0;
        TreeNode *ans=solve(inorder, preorder, preorderIndex, 0, n-1, n);
        return ans;
    }
};