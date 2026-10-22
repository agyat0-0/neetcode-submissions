class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<bool>> visited(n,vector<bool>(m,0));
       int res = 0;
       for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(!(visited[i][j]) && grid[i][j]=='1') {
                visited[i][j]=1;
                ++res;
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()) {
                    auto it = q.front();
                    q.pop();
                    int x = it.first;
                    int y = it.second;
                    if(x+1<n && visited[x+1][y]==0 && grid[x+1][y]=='1') {
                        q.push({x+1,y});
                        visited[x+1][y] = 1;
                    }

                    if(x-1>=0 && visited[x-1][y]==0 && grid[x-1][y]=='1') {
                        q.push({x-1,y});
                        visited[x-1][y] = 1;
                    }

                    if(y+1<m && visited[x][y+1]==0 && grid[x][y+1]=='1') {
                        q.push({x,y+1});
                        visited[x][y+1]=1;
                    }

                     if(y-1>=0 && visited[x][y-1]==0 && grid[x][y-1]=='1') {
                        q.push({x,y-1});
                        visited[x][y-1]=1;
                    }

                }
            }
        }
       } 

       return res;
    }
};
