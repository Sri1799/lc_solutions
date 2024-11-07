class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> v(25, 0);
        for (int i=0;i<25;i++)
        {
            for (auto &c:candidates)
            {
                if (c & (1<<i))
                    v[i]++;
            }
        }

        return *max_element(v.begin(), v.end());
    }
};
