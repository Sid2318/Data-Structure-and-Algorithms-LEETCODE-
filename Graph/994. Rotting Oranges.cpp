class Solution {
private:
    void display(vector<vector<int>>& grid){
        int nr = grid.size();
        int nc = grid[0].size();
        for(int i=0;i<nr;i++){
            for(int j=0;j<nc;j++){
                cout<<grid[i][j]<<", ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        // ((r,c),t)
        vector<vector<int>> visited(nr, vector<int>(nc, 0));

        //see all the rotten oranges at t =0
        for(int i=0;i<nr;i++){
            for(int j=0;j<nc;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
                else{
                    visited[i][j] =0;
                }
            }
        }

        int tm =0;
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,1,0,-1};

        //after t= 0
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            tm = max(t,tm);
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<nr && ncol>=0 && ncol<nc && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    visited[nrow][ncol] = 1;
                    q.push({{nrow,ncol},t+1});
                }
            }
            cout<<t<<endl;
            display(grid);
        }

        //check if not visited and is 1
        for(int i=0;i<nr;i++){
            for(int j=0;j<nc;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    return -1;
                }
            }
        }

        return tm;
    }
};














// class Solution {
// private:
//     vector<vector<int>> make_adj_list(vector<vector<int>> grid){
//         vector<vector<int>> adj(grid.size());
//         for(int i=0;i<grid.size();i++){
//             for(int j =0;j<grid[i].size();j++){
//                 if(i == j ){
//                     continue;
//                 }
//                 if(grid[i][j] == 1){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }
//         return adj;
//     }

//     void bfs(int start,vector<bool>& isVisited,vector<vector<int>>& adj,int& minute){
//         queue<int> q;
//         q.push(start);
//         isVisited[start] =1;

//         while(!q.empty()){
//             int i = q.front();
//             q.pop();
//             minute++;
//             for(auto& it: adj[i]){
//                 if(!isVisited[it]){
//                     q.push(it);
//                     isVisited[it] = 1;
//                 }
//             }
//         }

//         return;
//     }

// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int minute =0;

//         // step1 : Adjacency list
//         vector<bool> isVisited;
//         vector<vector<int>> adj = make_adj_list(grid);

//         //step 2 : find Start
//         int start=0;
//         for(int i=0;i<grid.size();i++){
//             for(int j =0;j<grid[i].size();j++){
//                 if(i == j ){
//                     continue;
//                 }
//                 if(grid[i][j] == 2){
//                     start = i;
//                 }
//             }
//         }

//         //step 3 : bfs traveral
//         bfs(start,isVisited,adj,minute);

//         //step 4: check if any is remaining
//         for(int i=0;i<isVisited.size();i++){
//             if(isVisited[i] == 0)
//             {
//                 return -1;
//             }
//         }
//         return minute+1;
//     }
// };
