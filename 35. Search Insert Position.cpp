/** Easy problem, but I need to think about execution more. Need to think
	about the edge cases which I did slightly better on. Didn't require
	looking at the solution.
**/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;
        
        if(nums[right] < target) return nums.size();
        else if(nums[left] > target) return left;
        
        int mid = 0;
        while(left <= right) {
            
            cout << mid << " : " << left << " : " << right << endl;
            mid = (left + right) / 2;
            
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        
        if(nums[mid] < target) mid++;
        
        return mid;
    }
};
