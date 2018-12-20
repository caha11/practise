class Solution {
public:
    
/** Brute Force, VERY SLOW    
    int maxArea(vector<int>& height) {
        if(height.size() == 1) return 0;
        int maxArea = 0;
        
        for(int i = 0; i < height.size(); i++) {
            for(int j = i + 1; j < height.size(); j++) {
                int minNum = min(height[i], height[j]);
                maxArea = max(maxArea, minNum * (j - i));
                //cout << maxArea << endl;
            }
        }
        return maxArea;
    } 
**/

/** Simple approach actually, have 2 points, 1 on left and 1 on right. Probably can spend more time
    thinking about it before looking at the solution.
**/
    int maxArea(vector<int>& height) {
        if(height.size() == 1) return 0;
        int maxArea = 0;
        int minNum = 0;
        int l = 0;
        int r = height.size() - 1;
        
        while(l != r) {
            if(height[l] < height[r]) {
                minNum = height[l];
                maxArea = max(maxArea, minNum * (r - l));
                l++;
            } else {
                minNum = height[r];
                maxArea = max(maxArea, minNum * (r - l));
                r--;
            }
        }
        
        return maxArea;
    }
    
};
