// Problem Link: https://leetcode.com/problems/sudoku-solver/solution/
// T.C: O((9!)^9)

class Solution {
public:
    bool solved = false;
    bool isSafeMove(int row, int col, char num, vector<vector<char>>& board){

        // row check
        for(int i=0;i<9;i++){
            if(board[row][i] == num)
                return false;
        }
        // col check
        for(int i=0;i<9;i++){
            if(board[i][col] == num)
                return false;
        }
        int rowStart = (row/3) * 3;
        int colStart = (col/3) * 3;

        // square check
        for(int i=rowStart;i<rowStart+3; i++){
            for(int j=colStart; j<colStart+3; j++){
                if(board[i][j] == num)
                    return false;
            }
        }
        return true;
    }

    void sudoku(int row, int col, vector<vector<char>>& board){

        // once the board is solved no need to do further changes
        if(solved)
            return;

        if(row == 9){
            solved = true;
            return;
        }

        if(col == 9){
            sudoku(row+1,0,board);
            return;
        }

        if(board[row][col] != '.'){
            sudoku(row, col+1, board);
            return;
        }
        for(char i='1';i<='9';i++){
            if(isSafeMove(row,col,i,board)){
                board[row][col] = i;
                sudoku(row, col+1, board);
                if(!solved)
                board[row][col] = '.';
            }
        }

    }

    void solveSudoku(vector<vector<char>>& board) {
        sudoku(0, 0, board);
    }
};
