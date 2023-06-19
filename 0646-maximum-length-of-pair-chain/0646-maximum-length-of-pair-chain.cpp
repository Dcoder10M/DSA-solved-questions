class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());

        int n = pairs.size();
        vector<int> lis(n,1);
        int res = 1;

        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(pairs[i][0] > pairs[j][1]){
                    lis[i] = max(lis[i], lis[j]+1);
                }
                res = max(res, lis[i]);
            }
        }
        return res;
    }
};