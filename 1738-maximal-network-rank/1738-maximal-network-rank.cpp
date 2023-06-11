class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> v(n,0);
        set<pair<int,int>> s;
        for(auto i:roads){
            v[i[0]]++;
            v[i[1]]++;
            s.insert({i[0],i[1]});
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(s.find({i,j})!=s.end() || s.find({j,i})!=s.end()){
                    ans=max(ans,v[i]+v[j]-1);
                }else{
                    ans=max(ans,v[i]+v[j]);
                }
            }
        }return ans;
    }
};