class Solution {
public:
    int solve(vector<int> &nums,int mid){
        int ans=0;
        for(auto i:nums){
            ans+=(i+mid-1)/mid;
        }return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=0,high=1e7;
        while(low+1<high){
            int mid=(low+high)/2;
            if(solve(nums,mid)<=threshold)high=mid;
            else low=mid;
        }return high;
    }
};