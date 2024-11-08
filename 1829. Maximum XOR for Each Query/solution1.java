class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        
        int n = nums.length, val = (1<<maximumBit) - 1, prevXor = 0;
        int[] ans = new int[n];

        for (int i=0;i<nums.length;i++)
        {
            int idx = n-1-i;
            ans[idx] = val ^ prevXor ^ nums[i];
            prevXor = prevXor ^ nums[i];
        }

        return ans;
    }
}
