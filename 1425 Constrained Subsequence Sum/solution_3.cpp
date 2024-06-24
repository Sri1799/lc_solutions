class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        /*
        - the only time we would have to pop front from queue is to maintain the interval of searching into previous K and not more elements
        at most 1 element would have to be popped? why?
            - we could add at most K + 1 to queue (non increasing), this means for the next element - the i-k-1 is out of bounds, hence we
            pop it out
            - so we can just compare dq.front() to dp[i-k-1]
            even if dp[i-k-1] values appears more than once in the interval, the logic would take care of it.
            e.g. 0 X 0
            if X > 0 => the first 0 would have anyways been evicted as we are dealing with a monotonic non-increasing queue
            else if X < 0 => when the second 0 comes, X will be evicted so we will have 0 0 in queue
            else X == 0   => just add to queue
        */
        
        int n = nums.size(), ans = INT_MIN;
        vector<int> dp(n, 0);
        deque<int> dq;

        for (int i=0;i<n;i++)
        {   
            if (i>k && dq.front()==dp[i-k-1])
                dq.pop_front();

            dp[i] = max(nums[i], nums[i] + (dq.size() == 0 ? 0 : dq.front()));
            ans = max(ans, dp[i]);

            while (dq.size() && dq.back()<dp[i])
                dq.pop_back();
            
            dq.push_back(dp[i]);
        }

        return ans;
    }
};
