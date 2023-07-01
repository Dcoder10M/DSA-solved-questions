class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,1e8));
        for(auto i:edges){
            adj[i[0]][i[1]]=i[2];
            adj[i[1]][i[0]]=i[2];
        }
        for(int i=0;i<n;i++)adj[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        int ans=0;
        int mx=1e8;
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=0;j<n;j++){
                if(adj[i][j]<=distanceThreshold)curr++;
            }
            if(curr<=mx){
                mx=curr;
                ans=i;
            }
        }return ans;
    }
};