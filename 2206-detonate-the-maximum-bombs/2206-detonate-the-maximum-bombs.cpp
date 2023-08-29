class Solution {
public:
    typedef long long ll;
    ll dfs(ll node,vector<vector<int>> &adj,vector<ll> &vis){
        vis[node]=1;
        ll ans=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                ans+=dfs(i,adj,vis);
            }
        }return ans;
    }
    ll maximumDetonation(vector<vector<int>>& bombs) {
        ll n=bombs.size();
        vector<vector<int>> adj(n);
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(i==j)continue;
                ll dis=(1ll*(bombs[i][0]-bombs[j][0]))*(1ll*(bombs[i][0]-bombs[j][0]))+(1ll*(bombs[i][1]-bombs[j][1])*(bombs[i][1]-bombs[j][1]));
                if(dis<=(1ll*bombs[i][2]*bombs[i][2]))adj[i].push_back(j);
            }
        }ll ans=0;
        for(ll i=0;i<n;i++){
            vector<ll> vis(n,0);
            ll temp=dfs(i,adj,vis);
            ans=max(ans,temp);
        }return ans;

    }
};