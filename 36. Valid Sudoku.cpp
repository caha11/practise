/** Has an 'ok' runtime, but could be written in a better way.
**/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows_chars(9);
        vector<unordered_set<char>> cols_chars(9);
        vector<unordered_set<char>> sub_boxes(9);
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                // Check if it's a valid char.
                if(board[i][j] == '.') continue;
                if(board[i][j] - '0' > 9 || board[i][j] - '0' < 0) return false;
                
                // Check for rows and columns.
                if(!rows_chars[i].insert(board[i][j]).second) return false;
                if(!cols_chars[j].insert(board[i][j]).second) return false;
                
                // Check for sub-boxes.
                // Check for top-boxes.
                if     (i <= 2 && j <= 2) {
                    if(!sub_boxes[0].insert(board[i][j]).second) return false;
                } else if(i <= 2 && j <= 5) {
                    if(!sub_boxes[1].insert(board[i][j]).second) return false;
                } else if(i <= 2 && j <= 8) {
                    if(!sub_boxes[2].insert(board[i][j]).second) return false;
                    
                // Check for middle boxes.
                } else if(i <= 5 && j <= 2) {
                    if(!sub_boxes[3].insert(board[i][j]).second) return false;
                } else if(i <= 5 && j <= 5) {
                    if(!sub_boxes[4].insert(board[i][j]).second) return false;
                } else if(i <= 5 && j <= 8) {
                    if(!sub_boxes[5].insert(board[i][j]).second) return false;
                }
            
                // Check for bottom boxes.
                else if(i <= 8 && j <= 2) {
                    if(!sub_boxes[6].insert(board[i][j]).second) return false;
                } else if(i <= 8 && j <= 5) {
                    if(!sub_boxes[7].insert(board[i][j]).second) return false;
                } else if(i <= 8 && j <= 8) {
                    if(!sub_boxes[8].insert(board[i][j]).second) return false;
                } else return false;
            }
        }
        return true;
    }
};
