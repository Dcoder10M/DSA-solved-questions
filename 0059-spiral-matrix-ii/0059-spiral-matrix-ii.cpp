class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m=n;
        int top=0,bottom=n-1,left=0,right=m-1;
        int dir=0;
        vector<vector<int>> fdgdf(n,vector<int>(m,0));
        int curr=1;
        while(top<=bottom && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    fdgdf[top][i]=curr++;
                }
                top++;
            }else if(dir==1){
                for(int i=top;i<=bottom;i++){
                    fdgdf[i][right]=curr++;
                }right--;
            }else if(dir==2){
                for(int i=right;i>=left;i--){
                    fdgdf[bottom][i]=curr++;
                }bottom--;
            }else{
                for(int i=bottom;i>=top;i--){
                    fdgdf[i][left]=curr++;
                }left++;
            }dir=(dir+1)%4;
        }return fdgdf;
    }
};