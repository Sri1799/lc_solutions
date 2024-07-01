/*
    let N be the number of nodes, E be the number of edges
    tc - O(E*klogk + E*3*3), k is max size of a v2[p] where 0<=p<N, k is max 4
        ~ O(k*E)
    sc - O(N*3)
        ~ O(N)
*/

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        /*
        - 3 most important points.
        - fix the middle 2 nodes (i.e. fix the middle edge)
        - sometimes, we don't have to take a whole sorted array, we could instead just take the max 1/2/3 and store those
            => reduces tc
        - we cannot have 'priority' do side A first and side B second => because there could be cases where choosing the
            side B first and side A second would return better results
        */
        int n = scores.size(), ans = -1;
        vector<vector<int>> v2(n);
        for (auto &e:edges)
        {
            int v = e[0], u = e[1];
            
            v2[v].push_back(u);
            v2[u].push_back(v);

            sort(v2[v].begin(), v2[v].end(), [&scores](const int i, const int j){
                return scores[i]>scores[j];
            });
            sort(v2[u].begin(), v2[u].end(), [&scores](const int i, const int j){
                return scores[i]>scores[j];
            });

            if (v2[v].size()>3)
                v2[v].pop_back();
            if (v2[u].size()>3)
                v2[u].pop_back();
        }

        for (auto &e:edges)
        {
            for (auto &left:v2[e[0]])
            {
                if (left == e[1])
                    continue;
                
                for (auto &riht:v2[e[1]])
                {
                    if (riht == e[0])
                        continue;

                    if (left == riht)
                        continue;
                    
                    ans = max(ans, scores[e[0]] + scores[e[1]] + scores[left] + scores[riht]);
                }
            }
        }

        return ans;
    }
};
