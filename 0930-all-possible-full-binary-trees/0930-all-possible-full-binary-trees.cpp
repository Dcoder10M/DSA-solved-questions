class Solution {
public:
    unordered_map<int, vector<TreeNode *>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if(n%2==0)return {};
        if(n==1){
            ans.push_back(new TreeNode(0));
            return dp[1]=ans;
        }
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        for(int i=1;i<n;i++){
            vector<TreeNode*> left=allPossibleFBT(i);
            vector<TreeNode*> right=allPossibleFBT(n-1-i);
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return dp[n]=ans;
    }
};