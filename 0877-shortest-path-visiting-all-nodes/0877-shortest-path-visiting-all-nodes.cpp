class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int ans=0;
        queue<pair<int,int>> q;
        map<pair<int,int>,int> s;
        for(int i=0;i<n;i++){
            int mask=1<<i;
            q.push({i,mask});
        }
        while(!q.empty()){
            int x=q.size();
            while(x--){
                pair<int,int> pp=q.front();
                q.pop();
                if(s[pp]==1)continue;
                s[pp]=1;
                int mask=pp.second;
                if(pp.second==((1<<n)-1))return ans;
                int node=pp.first;
                for(auto i:graph[node]){
                    q.push({i,mask|(1<<i)});
                }
            }ans++;
        }return ans;
    }
};