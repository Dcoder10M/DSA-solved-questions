class Solution {
public:
    bool validPartition(vector<int> &nums)
        {
            int n = nums.size();

            vector<int> dp(n + 1, 0);
            dp[0] = 1;//Emprt subarray case

            for (int index = 0; index < n; index++)
            {
                int i = index + 1;
                bool twoIdentical = false;
                bool threeIdentical = false;
                bool increasingSeq = false;

                if (index > 0 && nums[index] == nums[index - 1])
                {
                    twoIdentical = dp[i - 2];
                }

                if (index > 1 && nums[index] == nums[index - 1] && nums[index - 1] == nums[index - 2] && nums[index] == nums[index - 2])
                {
                    threeIdentical = dp[i - 3];
                }

                if (index > 1 && nums[index] == nums[index - 1] + 1 && nums[index - 1] == nums[index - 2] + 1)
                {
                    increasingSeq = dp[i - 3];
                }

                dp[i] = twoIdentical || threeIdentical || increasingSeq;
            }

            return dp[n];
        }

};