class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(auto i:nums)if(i==target)return 1;
        return 0;
    }
};