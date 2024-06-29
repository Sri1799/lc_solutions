/*
  the DFS will also be N^2, not N^3
  we get N^3 by just multiplying N*(V + E) where E is worst case N(N-1)/2 ==> N^2 
      so, the wrong time complexity becomes N(N + N^2) => N^3
  But thats not the case
  Image N(N-1)/2 edges. 
  0->1, 2, 3
  1->2, 3
  2->3
  
  In this case on call dfs on 0, N calls are made, loop size N-1 ~ O(2*N)
                  call dfs on 1, N-1 calls are made, loop size N-2 ~ 2*(N-1)
                  call dfs on 2, N-2 calls are made, loop size N-3 ~ 2*(N-3)
  
  hence the answer would be ~ 2*(N + N-1 + N-2 + N-3 ... + 1) ~ O(2*N^2) ~ O(N^2)
  tc - O(N + N + N^2 + N^2) ~ O(N^2)
  sc - O(N + N^2)
  max stack size is N, size of graph, ans is N^2
*/

class Solution {

    vector<vector<int>> ans;
    vector<vector<int>> graph;

    void dfs(int v, int par)
    {
        for (auto &u:graph[v])
        {
            if (ans[u].size() && ans[u].back() == par)
                continue;
            
            ans[u].push_back(par);
            dfs(u, par);
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        graph.assign(n, vector<int>());
        ans.assign(n, vector<int>());

        for (auto &e:edges)
        {
            graph[e[0]].push_back(e[1]);
        }

        for (int i=0;i<n;i++)
        {
            dfs(i, i);
        }

        return ans;
    }
};
