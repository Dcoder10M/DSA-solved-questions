class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto i:m){
            vector<int> temp=i.second;
            int ii=0,jj=0;
            while(ii<temp.size() && jj<temp.size()){
                while(temp[jj]-temp[ii]+1-jj+ii-1>k)
                ii++;
                ans=max(ans,jj-ii+1);
                jj++;
            }
        }return ans;
    }
};