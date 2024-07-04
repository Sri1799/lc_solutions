/*
  tc - O(M*logN*MlogN) ~ O((MlogN)^2)
  sc - O(M)
*/

class Solution {
public:
    int matrixMedian(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ls(m, 0), rs(m, n-1);
        int req = m*n / 2;
        while (1)
        {
            for (int i=0;i<m;i++)
            {
                if (rs[i]<ls[i])
                    continue;

                int mid = ls[i] + (rs[i] - ls[i])/2;
                int lhs = mid;

                for (int j=0;j<m;j++)
                {
                    if (j == i)
                        continue;
                    int idx = upper_bound(grid[j].begin(),
                    grid[j].end(), grid[i][mid]) - grid[j].begin();

                    lhs += idx;
                    if (lhs > req)
                        break;
                }

                if (lhs > req)
                {
                    rs[i] = mid - 1;
                }
                else if (lhs < req)
                {
                    ls[i] = mid + 1;
                }
                else
                {
                    return grid[i][mid];
                }
            }
        }

        return -1;
    }
};
