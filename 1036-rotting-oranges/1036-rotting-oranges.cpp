class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        queue<pair<int,int>> q;
        int n=grid.size(),m=grid[0].size();
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]==1)fresh++;
            }
        }if(fresh==0)return 0;
        if(q.size()==0)return -1;
        int rotten=0;
        int dx[]={1,0,-1,0};
        int dy[]={0,-1,0,1};
        while(!q.empty()){
            int sz=q.size();
            ans++;
            while(sz--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newx=x+dx[i];
                    int newy=y+dy[i];
                    if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==1){  
                        grid[newx][newy]=2;
                        rotten++;
                        if(rotten==fresh)return ans;
                        q.push({newx,newy});
                    }
                }
            }
        }
        return -1;
    }
};