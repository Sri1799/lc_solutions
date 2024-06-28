/*
  tc - O(n + nlogn)
  sc - O(n)
*/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        /*  
        - max number to max freq nodes
        */
        unordered_map<int,int> m;
        for (auto &road:roads)
        {
            m[road[0]]++;
            m[road[1]]++;
        }

        vector<long long> freqs;
        for (auto &it:m)
            freqs.push_back(it.second);

        long long ans = 0, cnt = n;
        sort(freqs.begin(), freqs.end());

        for (int i=freqs.size()-1;i>=0;i--)
        {
            ans += freqs[i]*cnt;
            cnt--;
        }

        return ans;
    }
};
