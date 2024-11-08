class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int val = (1<<maximumBit) - 1;
        vector<int> ans;
        int prevXor = 0, currXor = 0;

        for (auto &n:nums)
        {
            currXor = prevXor ^ n;
            ans.push_back(val ^ currXor);
            prevXor = currXor;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
