class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> time(n, vector<int> (m, -1));
        int ans = 0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i, j});
                    time[i][j] = 0;
                }
            }
        } 
        int dirR[] = {-1, 1, 0, 0};
        int dirC[] = {0, 0, -1, 1};
        while(!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            
            for(int k = 0; k<4; k++)
            {
                int newR = r + dirR[k];
                int newC = c + dirC[k];
                if (newR >=0 && newR < n && newC >=0 && newC < m &&
                grid[newR][newC]==1 && time[newR][newC]==-1)
                {
                    time[newR][newC] = time[r][c] + 1;
                    q.push({newR, newC});
                }
            }
        }
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (grid[i][j]==1 && time[i][j]==-1)return -1;
                if (time[i][j]>ans)ans = time[i][j];
            }
        } 
        return ans;
    }
};
