// Beats 96%
/*
  partial_sort time complexity is NlogK
  tc - O(E + N*(max number of edges a node can have)*log3 + E*3*3)
  sc - O(N*(max number of edges a node can have

  N*(max number of edges a node can have) ~ E
*/

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        
        int n = scores.size();
        vector<vector<int>> top3(n);
        for (auto &e:edges)
        {
            top3[e[0]].push_back(e[1]);
            top3[e[1]].push_back(e[0]);
        }

        for (auto &v:top3)
        {
            partial_sort(v.begin(), v.begin() + min((int)v.size(), 3), v.end(), 
            [&scores](const int &j, const int &k){
                return scores[j]>scores[k];
            });

            v.resize(min((int)v.size(), 3));
        }

        int ans = -1;
        for (auto &e:edges)
        {
            for (auto &vv:top3[e[0]])
            {
                for (auto &uu:top3[e[1]])
                {
                    if (vv == e[1] || uu == e[0] || vv == uu)
                        continue;
                    
                    ans = max(ans, scores[e[0]] + scores[vv] + scores[e[1]] + scores[uu]);
                }
            }
        }

        return ans;
    }
};
