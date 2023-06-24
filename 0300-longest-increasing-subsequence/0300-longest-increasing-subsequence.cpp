class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>lis.back())lis.push_back(nums[i]);
            else{
                int pos=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
                lis[pos]=nums[i];
            }
        }return lis.size();
    }
};