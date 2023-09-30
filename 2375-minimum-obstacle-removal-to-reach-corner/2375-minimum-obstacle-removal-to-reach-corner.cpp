class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        if(grid[0][0]==1)pq.push({1,{0,0}});
        else pq.push({0,{0,0}});
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};
        vector<vector<int>> dist(n,vector<int>(m,1e8));
        dist[0][0]=grid[0][0];
        while(!pq.empty()){
            int obstacle=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==n-1 && y==m-1)return obstacle;
            for(int k=0;k<4;k++){
                int row=x+dx[k];
                int col=y+dy[k];
                if(row>=0 && row<n && col>=0 && col<m){
                    if(obstacle+grid[row][col]<dist[row][col]){
                        pq.push({obstacle+grid[row][col],{row,col}});
                        dist[row][col]=obstacle+grid[row][col];
                    }
                }
            }
        }return -1;
    }
};