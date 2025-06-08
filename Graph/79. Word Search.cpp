class Solution {
private:
    bool dfs(int curr,int i,int j,vector<vector<char>>& board, string word){
        if(curr == word.size()){
            return true;
        }
        if(i<0 || i>= board.size() || j<0 || j>= board[0].size() || board[i][j] != word[curr]){
            return false;
        }

        char ch = word[curr];
        board[i][j] = '*'; //mark visited

        bool found =( dfs(curr+1,i+1,j,board,word) ||
                      dfs(curr+1,i,j-1,board,word) ||
                      dfs(curr+1,i,j+1,board,word) ||
                      dfs(curr+1,i-1,j,board,word) );
        
        board[i][j] = ch; //restore
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(0,i,j,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};
