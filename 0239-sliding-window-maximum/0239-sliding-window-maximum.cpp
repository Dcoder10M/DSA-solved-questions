class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> pq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            pq.insert(nums[i]);
            if(i>=k-1){
                auto it=pq.end();
                it--;
                ans.push_back(*it);
                pq.erase(pq.find(nums[i-k+1]));
            }
        }return ans;
    }
};