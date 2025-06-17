class Solution {
private:
    void bfs(vector<vector<int>>& visited,int r1, int c1,vector<vector<char>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
      
        queue<pair<int,int>> q;
        q.push({r1,c1});
        visited[r1][c1] = 1;

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr<rows && nc<cols && nc>=0 && nr>=0 && grid[nr][nc] == '1' && !visited[nr][nc]){
                    q.push({nr,nc});
                    visited[nr][nc] =1;
                }
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited(rows,vector<int> (cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == '1'&& !visited[i][j]){
                    island++;
                    bfs(visited,i,j,grid);
                }
            }
        }
        
        return island;
    }
};
