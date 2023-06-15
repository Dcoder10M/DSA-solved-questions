class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> currSubset;

        sort(nums.begin(), nums.end());
        permutations(nums, 0, output);

        return output;
    }
private:
    void permutations(vector<int> const& nums, int pos, vector<vector<int>>& output) {
        output.push_back(nums);

        for(int i = pos; i < nums.size(); ++i) {
            auto tmp = nums;
            while (pos < nums.size()-1) {
                ++pos;
                if (tmp[i] != tmp[pos]) {
                    swap(tmp[i], tmp[pos]);
                    permutations(tmp, i+1, output);
                }
            }
            pos = i;
        }
    }
};