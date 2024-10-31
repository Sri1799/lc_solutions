/*
  tc - O(N^2)
  sc - O(N^2)
*/

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        /*
            - any number b/w 1 to n-2
            - for each find longest inc subseq ending at or before i-1, with a val < nums[i]
                and longest inc subseq (reverse) ending at i+1 or above, with a val < nums[i]

            - what to use in order to keep track of the val of the elem and the longest inc subseq ending
            on it in ltr and rtl?
            - calculate lis
            - calculate rlis
            --> find the max lis ending for a num < nums[i]
                -> iterate 0 to i-1
            --> find the max rlis ending for a num < nums[i]
                -> iterate i+1 to n-1
            --> to remove = min(to remove so far, total - 1 - lis - rlis)
            - O(N*N)
        */
        int n = nums.size();
        vector<int> lis(n, 1), rlis(n, 1);

        for (int i=1;i<n;i++)
        {
            for (int j=0;j<i;j++)
            {
                if (nums[i] > nums[j])
                    lis[i] = max(lis[i], 1 + lis[j]);
            }
        }

        for (int i=n-2;i>=0;i--)
        {
            for (int j=i+1;j<n;j++)
            {
                if (nums[i] > nums[j])
                    rlis[i] = max(rlis[i], 1 + rlis[j]);
            }
        }

        int torem = n;
        for (int i=1;i<n-1;i++)
        {
            // l is longest increasing subseq for mountain i
            // r is longest decreasing subseq for mountain i
            int l = 0, r = 0;
            for (int j=0;j<i;j++)
            {
                if (nums[j] >= nums[i])
                    continue;
                
                l = max(l, lis[j]);
            }

            if (!l)
                continue;

            for (int j=i+1;j<n;j++)
            {
                if (nums[j] >= nums[i])
                    continue;

                r = max(r, rlis[j]);
            }

            if (!r)
                continue;

            torem = min(torem, n - (1 + l + r));
        }

        return torem;
    }
};
