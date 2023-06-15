class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int top=0,bottom=n-1,left=0,right=m-1;
        int dir=0;
        // int ans=0;
        // int cnt=0;
        vector<int> ans;
        while(top<=bottom && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    ans.push_back(a[top][i]);
                }
                top++;
            }else if(dir==1){
                for(int i=top;i<=bottom;i++){
                    ans.push_back(a[i][right]);
                }right--;
            }else if(dir==2){
                for(int i=right;i>=left;i--){
                    ans.push_back(a[bottom][i]);
                }bottom--;
            }else{
                for(int i=bottom;i>=top;i--){
                    ans.push_back(a[i][left]);
                }left++;
            }dir=(dir+1)%4;
        }return ans;
    }
};