class Solution {
public:
    int steps(int n,int dp[]){
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int one=steps(n-1,dp);
        int two=steps(n-2,dp);
        return dp[n]=one+two;
    }
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return steps(n,dp);
    }
};