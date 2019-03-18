/**
	Not that hard of a problem, was too lazy to think myself. Need to take more time to think.
**/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> sums(rows, vector<int>(cols, grid[0][0]));
        
        
        for(int i = 1; i < cols; i++) sums[0][i] = sums[0][i - 1] + grid[0][i];
        for(int i = 1; i < rows; i++) sums[i][0] = sums[i - 1][0] + grid[i][0];
        
        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                sums[i][j] = min(sums[i - 1][j], sums[i][j - 1]) + grid[i][j];
            }
        }
        
        return sums[rows - 1][cols - 1];
    }
};
