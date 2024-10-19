/*
    TC O(1)*O(logN)
    SC O(logN)
*/

class Solution {
public:
    char findKthBit(int n, int k) {
        /*
            3 1
            2 1
            1 1
        */
        if (n == 1)
            return '0';

        int mid = pow(2,n-1);

        if (k == mid)
            return '1';
        else if (k < mid)
            return findKthBit(n - 1, k);
        
        // k > mid
        int keff = k - mid;
        keff = pow(2, n-1) - keff;
        char c = findKthBit(n - 1, keff);

        return c == '0' ? '1' : '0';
    }
};
