class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for(auto i:paths){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(ans[i]==0){ 
                ans[i]=1;
                    queue<int> q;q.push(i);
                while(!q.empty()){
                   
                    int node=q.front();
                    q.pop();
                    for(auto i:adj[node]){
                        if(ans[i]==0 || ans[i]==ans[node]){
                            ans[i]=ans[node]+1;
                            if(ans[i]>4)ans[i]=ans[i]%4;
                            q.push(i);
                        }
                    }
                }
            }
        }
        return ans;
    }
};