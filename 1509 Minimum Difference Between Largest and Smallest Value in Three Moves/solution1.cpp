/*
  tc - O(NlogN)
  sc - O(1)
*/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        // a1 a2 a3 a4 a5 a6
        /*
        0 1 5 10 14
        10 10 10 10 14
        5 5 5 10 10
        1 1 5 5 5
        0 1 1 1 1
        */

        int n = nums.size();
        if (n <= 4)
            return 0;

        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i=0;i<4;i++)
        {
            ans = min(ans, nums[n - 4 + i] - nums[i]);
        }

        return ans;
    }
};
