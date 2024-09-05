/*
  tc - O(M + 6*N)
  sc - O(N)
*/

class Solution {

public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int req = mean*(n + rolls.size()) - accumulate(begin(rolls), end(rolls), 0);

        // req has to go around the the n numbers
        vector<int> ans;
        bool cannotAdd = false;
        for (int i=0;i<n;i++)
        {
            int j = 6;
            for (j=6;j>=1;j--)
            {
                int rem = req - j;
                int lb = n - i - 1, ub = 6 * (n - i - 1);
                if (rem >= lb && rem <= ub)
                {
                    ans.push_back(j);
                    req -= j;
                    break;
                }
            }

            if (j == 0)
                return {};
        }

        return ans;
    }
};
