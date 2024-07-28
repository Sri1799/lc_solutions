class Solution {
public:
    int countBinarySubstrings(string s) {

        int n = s.length(), prev = 0, ans = 0, curr = 1;
        for (int i=1;i<n;i++)
        {
            if (s[i] != s[i-1])
            {
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            }
            else
            {
                curr++;
            }
        }

        return ans + min(prev, curr);
    }
};
