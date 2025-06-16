class Solution {
private:
    void bfs(vector<vector<int>>& image, int sr, int sc,int original, int color){
        queue<pair<int,int>> q;
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));

        q.push({sr,sc});
        visited[sr][sc] = 1; // mark the starting point as visited
        image[sr][sc] = color;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i =0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<image.size() && nc>=0 && nc<image[0].size() && !visited[nr][nc] && image[nr][nc] == original){
                    image[nr][nc] = color;
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        
        bfs(image,sr,sc,original,color);

        return image;
    }
};
