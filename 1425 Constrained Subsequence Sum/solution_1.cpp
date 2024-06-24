/*
  tc - O(n + n*logn) => O(nlogn)
  sc - O(n) => O(n)

  Everytime we need to keep some set of points ordered by value (to pull the minimum or maximum value) - map/set/multiset/priority_queue
  But if these points are removable (i.e. inserts + removals are possible like in a sliding window) - map is the best way, it handles duplicates (increase freq of val appearing), and allows erase of keys (e.g. if value corresponding to key is 0) AND it orders things perfectly

  get largest key in map ->
    m.rbegin()->first;
    (*m.rbegin()).first;
  get smallest key in map ->
    m.begin()->first;
    (*m.begin()).first
*/

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), l = 0;
        map<int,int> m;
        vector<int> dp(n, 0);
        for (int r=0;r<n;r++)
        {
            if (r-l == k+1)
            {
                // increment l
                m[dp[l]]--;
                if (m[dp[l]] == 0)
                    m.erase(dp[l]);
                l++;
            }

            int max_prev = r == 0 ? 0 : (m.rbegin()->first);
            dp[r] = max(nums[r], nums[r] + max_prev);
            m[dp[r]]++;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
