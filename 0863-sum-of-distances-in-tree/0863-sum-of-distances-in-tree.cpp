class Solution {
public:
    int nn;
    vector<int> cnt;
    vector<int> sub;
    vector<vector<int>> adj;
    vector<int> ans;
    void calc(int node,int par){
        cnt[node]=1;
        for(auto i:adj[node]){
            if(i!=par){
                calc(i,node);
                cnt[node]+=cnt[i];
                sub[node]+=sub[i]+cnt[i];
            }
        }
    }

    void solve(int node,int parent,int partial){
        ans[node]=sub[node];
        if(parent!=-1){
            ans[node]+=partial+cnt[0]-cnt[node];
        }    
        for(auto i:adj[node]){
            if(i!=parent){
                solve(i,node,ans[node]-sub[i]-cnt[i]);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        nn=n;
        cnt.resize(nn,0);
        sub.resize(nn,0);
        adj.resize(nn);
        ans.resize(nn,0);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        calc(0,-1);
        solve(0,-1,-1);
        for(auto i:sub){
            cout<<i<<" ";
        }cout<<endl;
        for(auto i:cnt){
            cout<<i<<" ";
        }cout<<endl;
        return ans;
    }
};