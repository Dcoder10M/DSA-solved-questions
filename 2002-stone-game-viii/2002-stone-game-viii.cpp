class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        
        // Calculate the prefix sums
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }
        
        // Initialize the answer to the last element
        int ans = stones[n - 1];
        
        // Dynamic programming to find the maximum difference
        for (int i = n - 2; i >= 1; i--) {
            ans = max(ans, stones[i] - ans);
        }
        
        return ans;
    }
};
