class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<int> prev=triangle[n-1];
        for(int i=n-2;i>=0;i--){
            vector<int> curr=triangle[i];
            for(int j=0;j<m-(n-1-i);j++){
                curr[j]+=min(prev[j],prev[j+1]);
            }
            prev=curr;
        }
        return prev[0];
    }
};
