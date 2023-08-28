class Solution {
public:
    int solve(vector<int>& stones,int x,int y,int sum,vector<vector<int>> &dp){
        if(x>y)return 0;
        if(dp[x][y]!=-1)return dp[x][y];
        return dp[x][y]=max(
            (sum-stones[x])-solve(stones,x+1,y,sum-stones[x],dp),
            (sum-stones[y])-solve(stones,x,y-1,sum-stones[y],dp)
        );
    }
    int stoneGameVII(vector<int>& stones) {
        int sum=0;
        for(auto i:stones)sum+=i;
        vector<vector<int>> dp(stones.size()+1,vector<int>(stones.size()+1,-1));
        return solve(stones,0,stones.size()-1,sum,dp);
    }
};