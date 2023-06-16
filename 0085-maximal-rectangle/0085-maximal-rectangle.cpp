class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> mat(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')
                mat[i][j]=0;
                else {mat[i][j]=1;ans=1;}
            }
        }if(ans==0)return ans;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]!=0)
                {mat[i][j]+=mat[i][j-1];ans=max(ans,mat[i][j]);}
            }
        }
        int mn=1e7;
        int curr=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                for(int k=i;k<n;k++){
                    curr++;
                    mn=min(mn,mat[k][j]);
                    ans=max(ans,mn*curr);
                }
                curr=0;mn=1e7;
            }curr=0;mn=1e7;
        }return ans;
    }
};