class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans=board;
        int n=ans.size();
        int m=ans[0].size();
        int dx[]={-1,-1,0,1,1,1,0,-1};
        int dy[]={0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                for(int x=0;x<8;x++){
                    if(i+dx[x]>=0 && i+dx[x]<n && j+dy[x]>=0 && j+dy[x]<m)
                    count+=board[i+dx[x]][j+dy[x]];
                }
                if(count<2)ans[i][j]=0;
                else if(count==3 && board[i][j]==0)ans[i][j]=1;
                else if(count>3)ans[i][j]=0;
            }
        }board=ans;
    }
};