// Problem Link: https://leetcode.com/problems/valid-sudoku/

// Prefer this only.

class Solution {

public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<string> s;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j]=='.') continue;

                string x = to_string(board[i][j]);

                // create three unique identifications for each row, column and square.
                string rowComparision = "r"+to_string(j) + x; // r05
                string columnComparision = "c"+to_string(i) + x; // c05
                string squareComparision = "s"+to_string(i/3)+x+to_string(j/3); // s05

                if(s.find(rowComparision)!=s.end() || s.find(columnComparision)!=s.end() || s.find(squareComparision)!=s.end()){
                    return false;
                }else{
                    s.insert(rowComparision);
                    s.insert(columnComparision);
                    s.insert(squareComparision);
                }
            }
        }

        return true;
    }
};
