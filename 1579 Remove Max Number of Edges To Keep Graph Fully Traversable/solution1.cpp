/*
    tc - O(E)
    sc - O(6*N)
*/

class DSU
{
    private:
        vector<int> parent, rank, size;
        int n, comps = 0;

    public:
        DSU(int n)
        {
            this->n = n;
            parent.assign(n, -1);
            rank.assign(n, 0);
            size.assign(n, 0);
        }

        void addNode(int v)
        {
            parent[v] = v;
            rank[v] = 0;
            size[v] = 1;
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
                return false;
            
            comps--;
            if (rank[u] > rank[v])
                swap(v, u);
            
            parent[u] = v;
            if (rank[u] == rank[v])
                rank[v]++;
            
            size[v] += size[u];
            return true;
        }

        int getComps()
        {
            return comps;
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

        vector<vector<int>> both, aonly, bonly;
        for (auto &e:edges)
        {
            if (e[0] == 1)
            {
                aonly.push_back({e[1], e[2]});
            }
            else if (e[0] == 2)
            {
                bonly.push_back({e[1], e[2]});
            }
            else
            {
                both.push_back({e[1], e[2]});
            }
        }

        for (int i=0;i<both.size() && adsu->getComps()>1 && bdsu->getComps()>1;i++)
        {
            if (adsu->join(both[i][0]-1, both[i][1]-1))
                addedEdges++;
            bdsu->join(both[i][0]-1, both[i][1]-1);
        }

        for (int i=0;i<aonly.size() && adsu->getComps()>1;i++)
        {
            if (adsu->join(aonly[i][0]-1, aonly[i][1]-1))
                addedEdges++;
        }

        if (adsu->getComps()>1)
            return -1;

        for (int i=0;i<bonly.size() && bdsu->getComps()>1;i++)
        {
            if (bdsu->join(bonly[i][0]-1, bonly[i][1]-1))
                addedEdges++;
        }

        if (bdsu->getComps()>1)
            return -1;

        return edges.size() - addedEdges;
    }
};
