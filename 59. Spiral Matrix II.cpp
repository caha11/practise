/** Not that hard, just didn't pay attention to the for loops.
* Just need to go in a spiral
**/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(n));
        
        int current_num = 1;
        int left = 0;
        int right = n - 1;
        int bottom = n - 1;
        int top = 0;
        
        
         while(top <= bottom && left <= right) {
            
            for(int i = left; i <= right; i++) {
                ans[top][i] = current_num;
                current_num++;
            }
            top++;
            
            for(int i = top; i <= bottom; i++) {
                ans[i][right] = current_num;
                current_num++;
            }
            right--;
            
            for(int i = right; i >= left; i--) {
                ans[bottom][i] = current_num;
                current_num++;
            }
            bottom--;
            
            for(int i = bottom; i >= top; i--) {
                ans[i][left] = current_num;
                current_num++;
            }
            left++;
            
        }
        
        return ans;
    }
};
