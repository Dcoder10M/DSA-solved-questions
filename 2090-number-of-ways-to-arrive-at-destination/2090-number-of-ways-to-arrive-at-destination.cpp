class Solution {
public:
    long long mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> adj(n);
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        vector<long long> dist(n,1e18);
        dist[0]=0;
        vector<long long> ways(n,0);
        ways[0]=1;

        while(!pq.empty()){
            long long node=pq.top().second;
            long long tillnow=pq.top().first;
            pq.pop();
            for(auto i:adj[node]){
                if(dist[i.first]>tillnow+i.second){
                    dist[i.first]=tillnow+i.second;
                    pq.push({dist[i.first],i.first});
                    ways[i.first]=ways[node]%mod;
                }else if(dist[i.first]==tillnow+i.second){
                    ways[i.first]=(ways[i.first]+ways[node])%mod;
                }
            }
        }return ways[n-1]%mod;
    }
};