class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mpp;
        queue<TreeNode*> q;
        q.push(root);
        //We are adding links back to the parent from the child
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            //now add links while adding elemnets into the queue left and right
            if(tmp->left){
                q.push(tmp->left);
                mpp[tmp->left] = tmp;
            }
            if(tmp->right){
                q.push(tmp->right);
                mpp[tmp->right] = tmp;
            }
        }
        set<TreeNode*> vis;
        int dist = 0;
        while(!q.empty()) q.pop();
        q.push(target);
        vis.insert(target);
    while (dist != k) {
        int size = q.size();
        while (size > 0) {
            auto curr = q.front();
            q.pop();
            size--;

            if (curr->left && vis.find(curr->left) == vis.end()) {
                q.push(curr->left);
                vis.insert(curr->left);
            }
            if (curr->right && vis.find(curr->right) == vis.end()) {
                q.push(curr->right);
                vis.insert(curr->right);
            }
            if (mpp.find(curr) != mpp.end() && vis.find(mpp[curr]) == vis.end()) {
                q.push(mpp[curr]);
                vis.insert(mpp[curr]);
            }
        }
        dist++;
    }

    vector<int> ans;
    while (!q.empty()) {
        ans.push_back(q.front()->val);
        q.pop();
    }
        return ans;
    }
};