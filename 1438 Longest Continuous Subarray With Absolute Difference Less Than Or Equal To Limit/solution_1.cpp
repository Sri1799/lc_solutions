/*
  let N be number of unique elements in the nums
  tc - O(N*(logN + logN)), N into logN for lookup/insert/erase 
  sc - O(N)
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        /*
            - longest subarray s.t. diff b/w min and max is <= limit
            - maintain the vals of min and max read so far in the subarray
            - def. ans = 1
            - if greater than limit
                - we need to increment l till we push out the number causing this difference
                (still l<=r)
                - can have duplicates of the number
                - cannot reposition r each time => O(n^2)
                - maintain an ordered map, decrement freq as l++, if freq == 0, remove from map, update maxsf, minsf
                - to get next highest just do itr to get it (freq.rbegin() will return ptr to max key/min key)
                - maintain maxsf, minsf
            - else
                r++

            ans = max(ans, r - l + 1);


            lim = 4
            8 2 4 7
            l
              r 
        */
        int ans = 0, n = nums.size();
        if (!n)
            return ans;

        map<int,int> freq;
        int l = 0, maxsf = nums[0], minsf = nums[0];
        for (int r=0;r<n;r++)
        {
            freq[nums[r]]++;
            maxsf = max(maxsf, nums[r]);
            minsf = min(minsf, nums[r]);
            int diff = maxsf-minsf;
            if (diff>limit)
            {
                while (diff>limit)
                {
                    freq[nums[l]]--;
                    if (freq[nums[l]] == 0)
                        freq.erase(nums[l]);
                    l++;
                    minsf = (*freq.begin()).first;
                    maxsf = (*freq.rbegin()).first;
                    diff = maxsf - minsf;
                }
            }
            else
            {
                ans = max(ans, r - l + 1);
            }
        }

        /*
            8 2 4 7
              l
                  r

            freq 
            2 - 1
            4 - 1
            7 - 1

            maxsf = 7
            minsf = 2
            diff = 2
            ans = 2

        */

        return ans;
    }
    /*
    tc - O(NlogN)
    sc - O(N)
    */
};
