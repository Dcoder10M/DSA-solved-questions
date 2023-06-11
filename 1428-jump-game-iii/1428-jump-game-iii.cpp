class Solution {
public:
    bool dfs(int node,vector<int> &vis,vector<int> &arr){
        if(arr[node]==0)return true;
        if(vis[node]==1)return false;
        vis[node]=true;
        bool ans=false;
        if(node+arr[node]<arr.size())ans=ans|dfs(node+arr[node],vis,arr);
        if(node-arr[node]>=0)ans=ans|dfs(node-arr[node],vis,arr);
        return ans;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> vis(n,0);
        // vis[start]=1;
        return dfs(start,vis,arr);
    }
};