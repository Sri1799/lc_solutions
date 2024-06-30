// Beats 96%

/*
  tc - O(E)
  sc - O(6*N)
*/

class DSU
{
    private:
        vector<int> parent, rank;

    public:
        int comps = 0;
        DSU(int n)
        {
            parent.assign(n, -1);
            rank.assign(n, 0);
        }

        void addNode(int v)
        {
            parent[v] = v;
            rank[v] = 0;
            comps++;
        }

        int getParent(int v)
        {
            if (parent[v] == v)
                return v;
            
            return parent[v] = getParent(parent[v]);
        }

        bool join(int v, int u)
        {
            v = getParent(v);
            u = getParent(u);

            if (v == u)
            {
                return false;
            }

            comps--;
            if (rank[u] > rank[v])
                swap(v, u);
            
            parent[u] = v;
            if (rank[u] == rank[v])
                rank[v]++;

            return true;
        }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        /*
        - for BOTH Alice & Bob, the entire graph has to be a single connected component
        - create dsu's for both Alice & Bob graphs (i.e. what can they traverse?)
        - we first keep adding the type 3 edges
            - keep adding while dsu->getNumberOfConnectComponents() > 1
        - if still
            - add alice specific edges
            - add bob specific edges
        - if edges run out && connected comps > 1 for Alice/Bob return -1
        - return total - numberAdded
        */
        if (edges.size() < n-1)
            return -1;

        int addedEdges = 0;
        DSU *adsu = new DSU(n);
        DSU *bdsu = new DSU(n);

        for (int i=0;i<n;i++)
        {
            adsu->addNode(i);
            bdsu->addNode(i);
        }

        // both
        for (auto &e:edges)
        {
            if (e[0] != 3)
                continue;

            if (adsu->join(e[1]-1, e[2]-1) && bdsu->join(e[1]-1, e[2]-1))
                addedEdges++;
        }

        // aonly
        for (auto &e:edges)
        {
            if (e[0] == 1)
            {
                if (adsu->join(e[1]-1, e[2]-1))
                    addedEdges++;
            }
            else if (e[0] == 2)
            {
                if (bdsu->join(e[1]-1, e[2]-1))
                    addedEdges++;
            }
        }

        if (adsu->comps>1 || bdsu->comps>1)
            return -1;

        return edges.size() - addedEdges;
    }
};
