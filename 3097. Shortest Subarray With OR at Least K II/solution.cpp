/*
  N is the number of elements
  tc - O(N)
  sc - O(1)
*/

bool operator>=(vector<int> &v, int p)
{
    int val = 0;
    for (int i=0;i<v.size();i++)
    {
        if (v[i])
            val = (val | (1<<i));
    }

    return val >= p;
}

void operator^=(vector<int> &v, int p)
{
    int idx = 0;
    while (p)
    {
        if (p & 1)
        {
            v[idx]--;
        }

        p /= 2;
        idx++;
    }
}

void operator|=(vector<int> &v, int p)
{
    int idx = 0;
    while (p)
    {
        if (p & 1)
        {
            v[idx]++;
        }

        p /= 2;
        idx++;
    }
}

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bits(32, 0);

        int min_len = INT_MAX, l = 0;
        for (int r=0;r<nums.size();r++)
        {
            bits |= nums[r];

            while (bits>=k && l<=r)
            {
                min_len = min(min_len, r - l + 1);
                bits ^= nums[l];
                l++;
            }
        }

        return min_len == INT_MAX ? -1 : min_len;
    }
};
