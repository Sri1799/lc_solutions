    /*
    tc - O(N^2)
    sc - O(N)
    */

class Solution {
    vector<vector<int>> graph;
    vector<vector<int>> ans;
    vector<bool> vis;

    void dfs(int v, int par, vector<bool> &vis)
    {
        vis[v] = true;
        ans[v].push_back(par);
        for (auto &u:graph[v])
        {
            if (!vis[u])
                dfs(u, par, vis);
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        graph.assign(n, vector<int>());
        ans.assign(n, vector<int>());
        vis.assign(n, false);

        for (auto &e:edges)
        {
            graph[e[0]].push_back(e[1]);
        }

        for (int v=0;v<n;v++)
        {
            vis.clear();
            vis.assign(n, false);

            for (auto &u:graph[v])
            {
                if (!vis[u])
                    dfs(u, v, vis);
            }
        }

        return ans;
    }
};
