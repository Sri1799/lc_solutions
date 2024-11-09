/*
  tc - O(log2(N))
  sc - O(1)
*/

class Solution {
public:
    long long minEnd(int n, int x_) {
        /*
            - keep track of 0 bits in x
            - if (n == 1) return x
            - bits set in N-1 bit representation, corresponding 0-bits are set in x
            - n = 10^8, no. of 0-bits required to handle = log2(10^8) = 8*3.33 ~28 bits (0-bits)
            - 10^8 is already 28 bits, that plus this extra 28 bits => breaching the 32 bit boundary for int
            - long long is required. check all bits 0 to 62, if 0 add to zeroBitPos vector
            - for N-1 bit representation, find all set bits and set the corresponding 0 bits using the zeroBitPos
            return x
        */
        long long x = x_;

        vector<int> zeroBitPos;
        for (int i=0;i<63;i++)
        {
            if ((x & (1ll << i)) == 0)
            {
                zeroBitPos.push_back(i);
            }
        }

        int idx = 0;
        n--;
        while (n)
        {
            if (n & 1)
            {
                x = (x | (1ll <<zeroBitPos[idx]));
            }

            n /= 2;
            idx++;
        }

        return x;
    }
};
