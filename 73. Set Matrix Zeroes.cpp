/* Pretty easy problem actually. Just was a little tired */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        if(matrix.size() == 0) return;
        if(matrix[0].size() == 0) return;
        
        vector<pair<int, int>> coords;
        size_t rows = matrix.size();
        size_t cols = matrix[0].size();
        
        
        for(size_t i = 0; i < rows; i++) {
            for(size_t j = 0; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    pair<int, int> curr_coords(i, j);
                    coords.push_back(curr_coords);
                }
            }
        }
        
        for(auto curr_coord : coords) {
            MatrixToZero(matrix, curr_coord.first, curr_coord.second);
        }
        cout << "lol" << endl;
    }
    
    void MatrixToZero(vector<vector<int>> &matrix, int x, int y) {
        for(int i = 0; i < matrix[0].size(); i++) {
            matrix[x][i] = 0;
        }
        
        for(int j = 0; j < matrix.size(); j++) {
            matrix[j][y] = 0;
        }
    }
};
