class Solution {
    public:
    int minBitFlips(int start, int goal) {
        int xor_result = start ^ goal, ans = 0;
        return __builtin_popcount(xor_result);
    }
};
