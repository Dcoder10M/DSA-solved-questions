class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            if(i>k-1){
                s.erase(s.find(nums[i-k]));
            }
            if(i>=k-1){
                auto itr=s.end();
                itr--;
                ans.push_back(*itr);
            }
        }return ans;
    }
};