class Solution {
public:
    vector<int> transf(int coord,int n)
    {
        int row=n-1-(coord-1)/(n);
        int col= (coord-1)%n;

        if(row%2==n%2) return {row,n-1-col};
        else return {row,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n=board.size() , steps=0;

        vector<vector<int>>vis(n,vector<int>(n,0));
        queue<int>qu;
        qu.push(1);
        vis[n-1][0]=1;

        while(!qu.empty())
        {
            int sz=qu.size();

            for(int i=0;i<sz;i++)
            {
                int coord=qu.front();
                qu.pop();

                if(coord==n*n) return steps;

                for(int i=1;i<=6;i++)
                {
                    if(coord+i>n*n) break;

                    vector<int>new_coord=transf(coord+i,n);
                    int new_row=new_coord[0] , new_col=new_coord[1];

                    if(vis[new_row][new_col]) continue; 
                    
                    vis[new_row][new_col]=1;

                    if(board[new_row][new_col]!=-1) 
                        qu.push(board[new_row][new_col]);
                    else 
                        qu.push(coord+i);
                }
            }
            steps++;
        }
        return -1;
    }
};