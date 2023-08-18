class Solution {
public:
    typedef long long ll;
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ll ans=0;
        vector<ll> v(n,0);
        for(auto i:roads){v[i[0]]++,v[i[1]]++;};
        sort(v.rbegin(),v.rend());
        ll curr=n;
        for(auto i:v){
            ans+=curr*i;
            curr--;
        }return ans;
    }
};