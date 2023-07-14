class Solution {
    
    bool isPossible(int row, int col, char c, vector<vector<char>>& board){
        for(int i = 0; i<9; i++){
            if(board[i][col]==c){
                return false;
            }
    
            if(board[row][i]==c){
                return false;
            }
            
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==c){
                return false;
            }
        }
        return true;
    }
    
    bool puzzle(vector<vector<char>>& board){
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                if(board[i][j]=='.'){
                    for(char c = '1'; c<='9'; c++){
                        if(isPossible(i,j,c,board)){
                        board[i][j] = c;
                        if(puzzle(board)) return true;
                        board[i][j] = '.';
                        }
                   }
                return false;
            }
        }
    }
    return true;
}
     
public:
    void solveSudoku(vector<vector<char>>& board) {
        puzzle(board);
    }
};