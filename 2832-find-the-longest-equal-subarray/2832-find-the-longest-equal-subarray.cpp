class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto it:m)
        {
            
            int sz=it.second.size();
            int i=0,j=0;
            while(j<sz)
            {

                while(it.second[j]-it.second[i]-(j-i)>k) i++;
                ans=max(ans,j-i+1);
                j++;
            }
            
        }
        return ans;
    }
};