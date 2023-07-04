class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=-1,high=nums.size();
        while(low+1<high){
            int mid=(low+high)/2;
            if(nums[mid]>=target)high=mid;
            else low=mid;
        }return high;
    }
};