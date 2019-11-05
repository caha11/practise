/* Pretty easy problem, standard binary sort, just need to be better
	with the edge cases like an empty vector. */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(!matrix.size() || !matrix[0].size()) return false;
        
        int col_size = matrix[0].size();
        int row_size = matrix.size();
        
        if(matrix[0][0] > target || matrix[row_size - 1][col_size - 1] < target) return false;

        int first = 0;
        int last = col_size * row_size - 1;
        
        while(first <= last) {
            int mid = (first + last) / 2;
            
            int col = mid % col_size;
            int row = mid / col_size;
            
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) last = mid - 1;
            else first = mid + 1;
        }
        return false;
    }
};
