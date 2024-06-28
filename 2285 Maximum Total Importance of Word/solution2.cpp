class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        /*  
        - max number to max freq nodes
        m[1] = 1
        m[0] = 1
        freqs = {0, 1}
        */
        long long freq[50005] = {0}; // using array over vector substantially brings down the time complexity
        for (auto &r:roads)
        {
            freq[r[0]]++;
            freq[r[1]]++;
        }

        sort(begin(freq), begin(freq) + n);

        long long ans = 0;
        for (int i=0;i<n;i++)
            ans += freq[i]*(i+1);

        return ans;
    }
};
