/*
  tc - O(N)
  sc - O(1)
*/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (auto &num:arr)
        {
            if (num%2)
            {
                if (cnt == 2)
                    return true;
                cnt++;
            }
            else
            {
                cnt = 0;
            }
        }

        return false;
    }
};
