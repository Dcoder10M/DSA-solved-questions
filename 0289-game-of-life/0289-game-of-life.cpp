class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        int dx[]={-1,-1,0,1,1,1,0,-1};
        int dy[]={0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                for(int x=0;x<8;x++){
                    if(i+dx[x]>=0 && i+dx[x]<n && j+dy[x]>=0 && j+dy[x]<m)
                    count+=(board[i+dx[x]][j+dy[x]])%10;
                }
                board[i][j]+=count*10;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=board[i][j]/10;
                if(count<2)board[i][j]=0;
                else if(count==3 && board[i][j]%10==0)board[i][j]=1;
                else if(count>3)board[i][j]=0;
                else{
                    board[i][j]=board[i][j]%10;
                }
            }
        }
    }
};