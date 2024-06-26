/*
sliding window + operator overloading to keep track of bits frequency of appearance
tc - O(N)
sc - O(N)
*/

bool operator>=(const vector<int>& v1, const vector<int> &v2)
{
    int n = v1.size();
    for (int i=n-1;i>=0;i--)
    {
        if (v1[i]>0 && !v2[i])
            return true;
        if (!v1[i] && v2[i]>0)
            return false;
    }

    return true;
}

void operator-=(vector<int> &v1, const vector<int> &v2)
{
    int n = v1.size();
    for (int i=0;i<n;i++)
    {
        v1[i] -= v2[i];
    }
}

void operator+=(vector<int> &v1, const vector<int> &v2)
{
    int n = v1.size();
    for (int i=0;i<n;i++)
    {
        v1[i] += v2[i];
    }
}

class Solution {

    void print(vector<int> &nums)
    {
        for (auto &num:nums)
            cout<<num<<" ";
        cout<<endl;
    }

    vector<int> getBits(int num)
    {
        vector<int> bits(6, 0);
        for (int j=0;j<=5;j++)
        {
            if (num & (1<<j))
            {
                bits[j]++;
            }
        }

        return bits;
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int p) {
        
        unordered_map<int,vector<int>> numToBits;
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            numToBits[nums[i]] = getBits(nums[i]);
        }

        if (!p)
            return 1;

        vector<int> req = getBits(p);
        vector<int> orsf(6, 0);
        print(req);
        int l = 0, ans = INT_MAX;
        for (int r=0;r<n;r++)
        {
            orsf += numToBits[nums[r]];
            print(orsf);
            while (orsf >= req)
            {
                ans = min(ans, r - l + 1);
                orsf -= numToBits[nums[l]];
                l++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
