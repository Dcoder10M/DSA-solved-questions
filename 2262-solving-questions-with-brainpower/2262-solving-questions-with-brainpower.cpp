class Solution {
public:

    long long solve(int i,vector<vector<int>> &questions,vector<long long> &dp)
    {
         if(i >= questions.size() )
         {
             return 0;
         }
         if(dp[i]!=-1)
         {
             return dp[i];
         }
        long long x=questions[i][0]+solve(i+questions[i][1]+1,questions,dp);
        long long y=0+solve(i+1,questions,dp);
        if(x > y)
        {
            return dp[i]=x;
        }
        return dp[i]=y;

    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n+1,-1);
        return solve(0,questions,dp);
    }
};