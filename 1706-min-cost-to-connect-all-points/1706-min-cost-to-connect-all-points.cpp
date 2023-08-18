class Solution {
public:
    typedef long long ll;
    class dsu{

    public:

    vector<ll> rank,parent,size;
    dsu(ll n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(ll i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    ll findPar(ll node){
        if(node==parent[node])
            return node;
        return parent[node]=findPar(parent[node]);
    }

    void unionByRank(ll x,ll y){
        ll ultx=findPar(x);
        ll ulty=findPar(y);
        if(ultx==ulty)return;
        if(rank[ultx]<rank[ulty]){
            parent[ultx]=ulty;
        }else if(rank[ultx]>rank[ulty]){
            parent[ulty]=ultx;
        }else{
            parent[ulty]=ultx;
            rank[ultx]++; 
        }
    }

     void unionBySize(ll x,ll y){
        ll ultx=findPar(x);
        ll ulty=findPar(y);
        if(ultx==ulty)return;
        if(size[ultx]<size[ulty]){
            parent[ultx]=ulty;
            size[ulty]+=size[ultx];
        }else{
            parent[ulty]=ultx;
            size[ultx]+=size[ulty];
        }
    }
};
    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.size()==0)return 0;
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
        int n=points.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int dis=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                pq.push({dis,i,j});
            }
        }
        dsu ds(n);
        int ans=0;
        while(!pq.empty()){
            int dis=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            pq.pop();
            if(ds.findPar(x)!=ds.findPar(y)){
                ans+=dis;
                ds.unionBySize(x,y);
            }
        }return ans;
    }
};