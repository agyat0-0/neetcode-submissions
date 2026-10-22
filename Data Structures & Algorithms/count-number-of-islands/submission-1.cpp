class Solution {
private:
    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = 1;

        int dirR[] = {-1, 1, 0, 0};
        int dirC[] = {0, 0, -1, 1};

        while(!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k<4; k++)
            {
                int newR = r + dirR[k];
                int newC = c + dirC[k];
                if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
                grid[newR][newC] == '1' && visited[newR][newC]==0)
                {
                    visited[newR][newC] = 1;
                    q.push({newR, newC});
                }
            }

        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int island_count = 0;
        vector<vector<int>> visited(n, vector<int> (m, 0));
        for(int i =0; i<n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j]== '1' && visited[i][j]==0)
                {
                        island_count++;
                        bfs(i, j, grid, visited);
                }
            }
        }
        return island_count;
    }
};
