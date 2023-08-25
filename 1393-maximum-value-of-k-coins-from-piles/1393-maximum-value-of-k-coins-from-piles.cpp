class Solution {
public:
    int solve(int ind,vector<vector<int>>& piles,int k,vector<vector<int>> &dp){
        if(ind==piles.size())return 0;
        if(k==0)return 0;
        if(dp[ind][k]!=-1)return dp[ind][k];
        int ans=solve(ind+1,piles,k,dp);
        int sum=0;
        int count=0;
        for(int i=0;i<piles[ind].size();i++){
            sum+=piles[ind][i];
            count++;
            if(k-count>=0)
            ans=max(ans,sum+solve(ind+1,piles,k-count,dp));
            else break;
        }return dp[ind][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size()+1,vector<int>(k+1,-1));
        return solve(0,piles,k,dp);
    }
};