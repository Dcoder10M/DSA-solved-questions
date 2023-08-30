class Solution {
public:
    int ans=-1;
    void dfs(int node,vector<int>& edges,unordered_map<int,int> &m,vector<int> &vis){
        vis[node]=1;
        int child=edges[node];
        if(child==-1)return;
        if(!vis[child]){
            m[child]=1+m[node];
            dfs(child,edges,m,vis);
        }else if(m.find(child)!=m.end()){
            ans=max(ans,m[node]-m[child]+1);
        }
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                unordered_map<int,int> m;
                m[i]=1;
                dfs(i,edges,m,vis);
            }
        }return ans;
    }
};