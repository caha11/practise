/** I've done this problem before.
**/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for(int layer = 0; layer < n/2; layer++) {
            int first = layer;
            int last = n - 1 - layer;
            
            for(int i = first; i < last; i++) {
                
                int offset = i - first;
                cout << "Offset: " << offset << " i: " << i << " layer: " << first << endl;
                
                int top = matrix[first][i]; // Saving top
                matrix[first][i] = matrix[last - offset][first]; // left
                matrix[last - offset][first] = matrix[last][last - offset]; // bottom
                matrix[last][last - offset] = matrix[i][last]; // right
                matrix[i][last] = top; // top
            
            }
        }
        
    }
};
