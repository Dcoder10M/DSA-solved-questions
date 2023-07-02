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
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int row=0,col=0;
        for(auto i:stones){
            row=max(row,i[0]);
            col=max(col,i[1]);
        }
        dsu ds(row+col+1);
        for(auto i:stones){
            ds.unionBySize(i[0],i[1]+row+1);
        }
        set<int> ss;
        for(auto i:stones){
            ss.insert(ds.findPar(i[0]));
        }return stones.size()-ss.size();
    }
};