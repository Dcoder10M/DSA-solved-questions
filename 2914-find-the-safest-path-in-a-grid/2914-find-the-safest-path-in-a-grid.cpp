class Solution {
public:
    vector<vector<int>>dict={{0,1},{1,0},{-1,0},{0,-1}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1) 
        return 0;

        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                 vis[i][j]=1;
                 q.push({0,{i,j}});
                }
            }
        }

        while(!q.empty())
        {
           pair<int,pair<int,int>>p=q.front();
           q.pop();
           int i=p.second.first;
           int j=p.second.second;
           int c=p.first;

           grid[i][j]=c;

           for(int k=0;k<4;k++)
           {
              int x=i+dict[k][0],y=j+dict[k][1];
              if(x>=0 && y>=0 && x<n && y<n && vis[x][y]==0)
              {
                  vis[x][y]=1;
                  q.push({c+1,{x,y}});
              }
           }
        }

        int safeFactor=INT_MAX;
        priority_queue<pair<int,pair<int,int>>>pq;
         vector<vector<int>>v(n,vector<int>(n,0));
        pq.push({grid[0][0],{0,0}});
        v[0][0]=1;
        while(!pq.empty())
        {
           pair<int,pair<int,int>>p=pq.top();
           pq.pop();
           int i=p.second.first;
           int j=p.second.second;
           int c=p.first;

           safeFactor=min(safeFactor,c);
           if(i==n-1 && j==n-1)
           break;

           for(int k=0;k<4;k++)
           {
              int x=i+dict[k][0],y=j+dict[k][1];
              if(x>=0 && y>=0 && x<n && y<n && v[x][y]==0)
              {
                  v[x][y]=1;
                  pq.push({grid[x][y],{x,y}});
              }
           }
        }
        
        return safeFactor;
    }
};