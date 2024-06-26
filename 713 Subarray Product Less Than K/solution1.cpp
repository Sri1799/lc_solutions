/*
  tc - O(N)
  sc - O(1)
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /*
        for loop of r, keep multipplying to the curr_subarray product (csp initialized to 1)
        every time a product > k, we increment l to reduc the csp
        at each iteration of r, we are basically calculating the number of subarrays that can be formed ending at that element, 
        if the csp (product so far > k), we need to increment l, to reduce subarray size and reduce csp so that csp once again
        falls less than k, 
        in which the number of subarrays ending at idx r = length of subarray
        */
        int n = nums.size(), l = 0, csp = 1, ans = 0;
        for (int r=0;r<n;r++)
        {
            csp *= nums[r];

            while (l<r+1 && csp>=k)
            {
                // increment l, only till invalidates the subarray (i.e. max position l can go to is r + 1)
                csp /= nums[l];
                l++;
            }

            if (csp<k)
            {
                ans += (r - l + 1);
            }
        }

        return ans;
    }
};
