/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> m;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){
                m[temp->left]=temp;
                q.push(temp->left);
            }if(temp->right){
                m[temp->right]=temp;
                q.push(temp->right);
            }
        }
        if(k==0)return {target->val};
        q.push(target);
        set<TreeNode*> vis;
        while(!q.empty()){
            int x=q.size();
            while(x--){
                TreeNode* temp=q.front();
                vis.insert(temp);
                q.pop();
                if(temp->left && vis.find(temp->left)==vis.end()){
                    q.push(temp->left);
                }if(temp->right && vis.find(temp->right)==vis.end()){
                    q.push(temp->right);
                }if(m.find(temp)!=m.end() && vis.find(m[temp])==vis.end())q.push(m[temp]);
            }k--;
            if(k==0)break;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }return ans;
    }
};