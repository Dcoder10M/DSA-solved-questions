class Solution {
public:    
    vector<vector<int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n,vector<int>(m, 100));
        vector<vector<int>> arrowDir = {{0,1}, {0,-1},{1, 0}, {-1, 0}};
        queue<pair<int,int>> q;
        q.push({0,0});
        res[0][0] = 0;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int x = curr.first, y = curr.second;
            
            for(auto &d:dir){
                int nx = x + d[0], ny = y + d[1];
                if(nx<0 || ny<0 || nx>=n || ny>=m)
                    continue;
                
                int cost = (d!=arrowDir[grid[x][y]-1]);
                if(res[nx][ny] > res[x][y] + cost){
                    q.push({nx,ny});
                    res[nx][ny] = res[x][y] + cost;
                }
            }
        }
        
        return res[n-1][m-1];
    }
};