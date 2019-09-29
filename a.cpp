 
 #include <bits/stdc++.h>

 using namespace std;
 
 int res = 0;
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid, int &size)
    {
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || !grid[i][j] || vis[i][j])
        { 
            return;
        }
        size++;
        vis[i][j] = true;
        dfs(i+1, j, vis, grid, size);
        dfs(i-1, j, vis, grid, size);
        dfs(i, j+1, vis, grid, size);
        dfs(i, j-1, vis, grid, size);
        return; 
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m, false));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j])
                {
                    int k = 0;
                    dfs(i, j, vis, grid, k);
                    res = max(res, k);
                }
                    
            }
        }
        return res;
    }

	int main()
	{
		vector<vector<int>> A = {
									{0,0,1,0,0,0,0,1,0,0,0,0,0},
									{0,0,0,0,0,0,0,1,1,1,0,0,0},
									{0,1,1,0,1,0,0,0,0,0,0,0,0},
									{0,1,0,0,1,1,0,0,1,0,1,0,0},
									{0,1,0,0,1,1,0,0,1,1,1,0,0},
									{0,0,0,0,0,0,0,0,0,0,1,0,0},
									{0,0,0,0,0,0,0,1,1,1,0,0,0},
									{0,0,0,0,0,0,0,1,1,0,0,0,0} };

		cout << maxAreaOfIsland(A);
        system("pause");
        return 0; 

	}