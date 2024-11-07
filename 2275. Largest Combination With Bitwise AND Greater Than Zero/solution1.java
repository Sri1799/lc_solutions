class Solution {
    public int largestCombination(int[] candidates) {
        int[] freq = new int[25];
        int maxFreq = 0;
        for (int i=0;i<25;i++)
        {
            for (int c:candidates)
            {
                if ((c & (1<<i)) > 0)
                {
                    freq[i]++;
                    maxFreq = Math.max(maxFreq, freq[i]);
                }
            }
        }

        return maxFreq;
    }
}
