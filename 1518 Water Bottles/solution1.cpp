class Solution {
public:
    int numWaterBottles(int a, int b) {
        
        int ans = 0;
        while (a>=b)
        {
            ans += (a/b)*b;
            a = a%b + (a/b);
        }   

        return ans + a;
    }
};
