/*
  N is number of elements
  tc - O(32*2*N) (every operation - or, remove_or, isGreaterThanOrEqual - requires you to go through 32 bits ; and each number you may go through it twice (or, remove_or))
  sc - O(1)
*/

class Solution {

    public boolean isGreaterThanOrEqual(int[] bits, int p)
    {
        int val = 0;
        for (int i=0;i<bits.length;i++)
        {
            if (bits[i] > 0)
                val |= (val | (1<<i));
        }

        return val >= p;
    }

    public void or(int[] bits, int p)
    {
        int idx = 0;
        while (p > 0)
        {
            if ((p & 1) > 0)
            {
                bits[idx]++;
            }

            p /= 2;
            idx++;
        }
    }

    public void remove_or(int[] bits, int p)
    {
        int idx = 0;
        while (p > 0)
        {
            if ((p & 1) > 0)
            {
                bits[idx]--;
            }

            p /= 2;
            idx++;
        }
    }

    public int minimumSubarrayLength(int[] nums, int k) {
        int l = 0, min_len = Integer.MAX_VALUE;
        int[] bits = new int[32];

        for (int r=0;r<nums.length;r++)
        {
            or(bits, nums[r]);

            while (isGreaterThanOrEqual(bits, k) && l<=r)
            {
                min_len = Integer.min(min_len, r - l + 1);
                remove_or(bits, nums[l]);
                l++;
            }
        }

        return min_len == Integer.MAX_VALUE ? -1 : min_len;
    }
}
