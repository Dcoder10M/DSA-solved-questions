class Solution {
public:
    typedef long long ll;
    bool solve(vector<int> &nums,int k,ll mid){
        ll count=1,curr=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid)return false;
            curr+=nums[i];
            if(curr>mid){
                curr=nums[i];
                count++;
            }
        }return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        if(nums.size()<k)return -1;
        ll low=-1,high=1e10;
        while(low+1<high){
            ll mid=(low+high)/2;
            if(solve(nums,k,mid))high=mid;
            else low=mid;
        }return high;
    }
};