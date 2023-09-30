class Solution {
public:
    int dp[501][501];
    int solve(int ind,int factor,vector<int>& a){
        if(ind==a.size()){
            return 0;
        }
        if(dp[ind][factor]!=-1)return dp[ind][factor];
        int take=factor*a[ind] + solve(ind+1,factor+1,a);
        int nottake=solve(ind+1,factor,a);
        return dp[ind][factor]=max(take,nottake);
    }
    int maxSatisfaction(vector<int>& a) {
        sort(a.begin(),a.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,1,a);
    }
};