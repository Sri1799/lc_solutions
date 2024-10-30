/*
  TC - O(NlogN)
  SC - O(N)
*/

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        /*
            - len >= 2
            - num = sq of prev num
            - len of longest
            - sort nums
                - maintain lsf
                - unordered_map<int,int> num and the MAX square streak len ending at it
        */
        sort(begin(nums), end(nums));
        unordered_map<int,int> ss;
        int lsf = 0;

        for (auto &n:nums)
        {
            int a = sqrt(n);
            if (a*a == n && ss.find(a) != ss.end())
            {
                ss[n] = ss[a] == 0 ? 2 : (ss[a] + 1);
                lsf = max(lsf, ss[n]);
            }
            else
            {
                ss[n] = 0;
            }
        }

        return lsf == 0 ? -1 : lsf;
    }
};
