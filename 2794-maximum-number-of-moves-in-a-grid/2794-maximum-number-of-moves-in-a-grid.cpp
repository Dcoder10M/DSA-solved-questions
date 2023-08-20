class Solution {
public:
    int solve(int i,int j,int &m,int &n,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i<0||j<0||i>=m||j>=n)return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int a=0,b=0,c=0;
        if(i-1>=0 && j+1<n&&grid[i-1][j+1]>grid[i][j]){
            a = solve(i-1,j+1,m,n,grid,dp);
        }
        if(i+1<m && j+1<n&&grid[i+1][j+1]>grid[i][j]){
            b = solve(i+1,j+1,m,n,grid,dp);
        }
        if(j+1<n&&grid[i][j+1]>grid[i][j]){
            c = solve(i,j+1,m,n,grid,dp);
        }
        return dp[i][j] = max({a,b,c})+1;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size(),i,j,ans=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(i = 0; i < m; i++){
                if(dp[i][0]==-1){
                    ans = max(ans,solve(i,0,m,n,grid,dp));
                }
        }
        return ans-1;
    }
};