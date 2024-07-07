/*
  tc - O(M*N)
  sc - O(M*N)
*/

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>> dpx(m + 1, vector<int>(n + 1, 0));
	vector<vector<int>> dpy(m + 1, vector<int>(n + 1, 0));
	int ans = 0;    	

	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			dpx[i + 1][j + 1] = (grid[i][j] == 'X' ? 1 : 0) + dpx[i][j + 1] + dpx[i + 1][j] - dpx[i][j];
			dpy[i + 1][j + 1] = (grid[i][j] == 'Y' ? 1 : 0) + dpy[i][j + 1] + dpy[i + 1][j] - dpy[i][j];
			if (dpx[i + 1][j + 1] > 0 && dpx[i + 1][j + 1] == dpy[i + 1][j + 1])
				ans++;
		}
	}

	return ans;
    }
};
