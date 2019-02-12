/** Almost got it right. Simple problem
**/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        
        if(matrix.size() == 0) return ans;
        
        int count = 0;
        
        int top_bound = 0;
        int bottom_bound = matrix.size() - 1;
        int left_bound = 0;
        int right_bound = matrix[0].size() - 1;
            
        while(true) {

            //top
            for(int i = left_bound; i <= right_bound; i++) ans.push_back(matrix[top_bound][i]);
            if(++top_bound > bottom_bound) break;
            //right
            for(int i = top_bound; i <= bottom_bound; i++) ans.push_back(matrix[i][right_bound]);
            if(--right_bound < left_bound) break;
            //bottom
            for(int i = right_bound; i >= left_bound; i--) ans.push_back(matrix[bottom_bound][i]);
            if(--bottom_bound < top_bound) break;
            //left
            for(int i = bottom_bound; i >= top_bound; i--) ans.push_back(matrix[i][left_bound]);
            if(++left_bound > right_bound) break;
            
        }
        return ans;
    }
};
