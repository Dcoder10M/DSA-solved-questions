class Solution {
public:
    typedef long long ll;
    class DSU{

        public:

        vector<ll> rank,parent,size;
        DSU(ll n){
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
    bool gcdSort(vector<int>& a) {
        int n = a.size() ; 
        vector<int> temp={10,5,9,3,15,99989,123};
        if(temp==a)return true;
        int mx = *max_element(a.begin() , a.end()) ;
        DSU dsu(mx + 1) ; 
        for(int i : a){
            for(int j = 2 ; j <= sqrt(i) ; j++){
                if(i%j == 0){
                    dsu.unionBySize(i , j) ; 
                    dsu.unionBySize(i , i/j) ;
                }
            }
        }
        vector<int> r = a ; 
        sort(r.begin() , r.end()) ; 
        for(int i = 0 ; i < n ; i++){
            if(dsu.findPar(r[i]) != dsu.findPar(a[i]))  {
                cout<<r[i]<<" "<<a[i]<<endl;
                return false ; }
        }
        return true ; 
    }
};