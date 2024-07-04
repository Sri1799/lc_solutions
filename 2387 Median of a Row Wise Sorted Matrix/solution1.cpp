/*
  A very naive solution
  tc - O(m*n/2 * m)
  sc - O(m)
*/

class Solution {
public:
    int matrixMedian(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int total = m*n;
        int lhs = total / 2;

        /*
        we need to cover 'lhs' number of items 
        and then the minimum of the remaining would be the answer
        */
        vector<int> indexes(m, 0);
        while (lhs--)
        {
            // get which row has the min element at the moment, increment it
            int row = -1;
            for (int i=0;i<m;i++)
            {
                if (indexes[i] == n)
                    continue;
                if (row == -1 || (grid[row][indexes[row]] > grid[i][indexes[i]]))
                    row = i;
            }

            indexes[row]++;
        }

        int ans = INT_MAX;
        for (int i=0;i<m;i++)
        {
            if (indexes[i] == n)
                continue;
            ans = min(ans, grid[i][indexes[i]]);
        }

        return ans;
    }
};
