/** The approach was good. Execution wasn't so good. Even though the code
	is similar to the solution. For some reason it's exceeding the time 
	limit.
**/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //if(nums.empty()) return -1;
        
        int nums_size = nums.size();
        
        int left = 0;
        int right = nums_size - 1;
        
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else if(nums[left] ) right = mid;
        }
        // Good.
        
        int intersection_index = left;
        
        left = 0;
        right = nums_size - 1;
        // Good.
        
        while(left <= right) {
            int mid = (left + right) / 2;
            //cout << mid << endl;
            int mid_conv = (mid + intersection_index) % nums_size;
            if(nums[mid_conv] == target) return mid_conv;
            if(nums[mid_conv] < target) left = mid + 1;
            else right = mid - 1;
        }
        
        return -1;
    }
};
