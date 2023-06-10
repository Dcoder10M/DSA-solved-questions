class Solution {
public :
    vector<vector<int>> ans;
    void dfs(int node,int des,vector<vector<int>>& adj,vector<int> &temp){
        if(node==des){
            temp.push_back(node);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(node);
        for(auto i:adj[node]){
            dfs(i,des,adj,temp);
        }   
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        ans.clear();
        vector<int> vis(n,0);
        vector<int> temp;
        dfs(0,n-1,graph,temp);
        return ans;
    }
};