/*
  tc - O(log2(N))
  sc - O(1)
*/

class Solution {
    public long minEnd(int n, int x_) {
        List<Integer> zeroBitPos = new ArrayList<>();

        long x = x_;
        long one = 1;
        for (int i=0;i<63;i++)
        {
            if ((x & (one << i)) == 0)
                zeroBitPos.add(i);
        }

        int idx = 0;
        n--;

        while (n > 0)
        {
            if ((n & 1) > 0)
            {
                x = (x | (one << zeroBitPos.get(idx)));
            }

            n /= 2;
            idx++;
        }

        return x;
    }
}
