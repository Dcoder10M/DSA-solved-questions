class Solution {
public:
    int find(int i,int j1,int j2,int n,int m,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp)
    {
        if(j1<0 || j2<0 || j1>=m || j2>=m)return INT_MIN;
        
        if(i==n-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1)
        {
            return dp[i][j1][j2];
        }
        
        int maxi = INT_MIN;
        
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        
        for(int dx=-1;dx<=+1;dx++)
        {
            for(int dy=-1;dy<=+1;dy++){
            int value= 0;
            if(j1==j2)
            {
                value = grid[i][j1]+ find(i+1,j1+dx, j2+dy,n,m,grid,dp);
            }else{
                value = grid[i][j1] + grid[i][j2]+find(i+1,j1+dx, j2+dy,n,m,grid,dp);
            }
            
           
            maxi=max(maxi,value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return find(0,0,grid[0].size()-1,n,m,grid,dp);    
    }
};