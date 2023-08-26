// #include <bits/stdc++.h>

class Solution {
public:
    int solve(int ind,int m,vector<int>& piles,vector<vector<int>> &dp){
        if(ind==piles.size())return 0;
        if(dp[ind][m]!=-1e8)return dp[ind][m];
        int ans=INT_MIN;
        int sum=0;
        int xx=(min((int)piles.size(),(int)(ind+m+m)));
        for(int i=ind;i<xx;i++){
            sum+=piles[i];
            ans=max(ans,sum-solve(i+1,max(i-ind+1,m),piles,dp));
        }return dp[ind][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(1000,vector<int>(1000,-1e8));
        int diff=solve(0,1,piles,dp);
        int sum=0;
        for(auto i:piles)sum+=i;
        return (sum+diff)/2;
    }
};