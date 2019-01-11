/** Easy problem, but I need to think about execution more. Need to think
	about the edge cases which I did slightly better on. Didn't require
	looking at the solution.
**/

/** Looked at a solution, and a smart thing was displayed. Instead of
	returning mid, return low instead.
**/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right) {
            
            int mid = (left + right) / 2;
            
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        
        return left;
    }
};
