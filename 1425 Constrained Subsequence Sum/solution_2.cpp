/*
    for for loop,
    max elements that will exist in dq at once is k+1
    tc - O(n)
    sc - O(n + k)
*/

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        /*
        Sliding window + maintaining maximum in prev interval == 'Decreasing deque' concept
        because we want the maximum sum, we can use DP + decreasing deque (decreasing deque for MAX so far from the
        eligible interval)
        - monotonically decreasing queue => gives 'nextGreater' elems
        - as the interval is sliding, we need to refresh the deque to not store values from outside the interval
        - to keep track of where is interval, and which values are in or out => we store indexes in dq rather than the value
        of the sum itself. The value of sum will be in the dp vector.
        */
        int n = nums.size(), ans = INT_MIN;
        vector<int> dp(n, 0);
        deque<int> dq;

        for (int i=0;i<n;i++)
        {
            // refresh
            while (dq.size() && dq.front()<i-k)
                dq.pop_front();

            dp[i] = max(nums[i], nums[i] + (dq.size() == 0 ? 0 : dp[dq.front()]));
            ans = max(ans, dp[i]);
            while (dq.size() && dp[dq.back()]<dp[i])
                dq.pop_back();
            
            dq.push_back(i);
        }

        return ans;
    }
};
