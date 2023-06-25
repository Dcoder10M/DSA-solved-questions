class Solution {
public:
    int solve(int row,int col,vector<vector<int>> &grid){
        int n=grid.size(),m=grid[0].size();
        if(row>=n)return col;
        bool right=false;
        if(col!=m-1 && grid[row][col+1]==1)right=true;
        bool left=false;
        if(col!=0 && grid[row][col-1]==-1)left=true;
        if(grid[row][col]==1){
            if(right){
                return solve(row+1,col+1,grid);
            }else return -1;
        }else{
            if(left){
                return solve(row+1,col-1,grid);
            }else return -1;
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        for(int i=0;i<grid[0].size();i++){
            ans.push_back(solve(0,i,grid));
        }return ans;
    }
};