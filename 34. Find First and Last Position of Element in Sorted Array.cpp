/** Need to think about edge cases more. Good: developed the solution
	on my own :).
**/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        
        if(nums.empty()) return vector<int>{-1, -1};
        if(nums.size() == 1 && nums[0] == target) return vector<int>{0, 0};
        
        
        int left = 0;
        int right = nums.size() - 1;
        int left_target_index = -1;
        
        while(left <= right) {
            //cout << "left: " << left << " right: " << right << endl;
            int mid = (left + right) / 2;

            if(nums[mid] == target) {
                left_target_index = mid;
                break;
            }
            else if(nums[mid] > target) right = mid - 1; 
            else left = left + 1;
        }
        
        //cout << "Found" << left_target_index << endl;
        if(left_target_index == -1) return vector<int>{-1, -1};
        
        int right_target_index = left_target_index;
        while(left_target_index - 1 >= 0 && nums[left_target_index - 1] == nums[right_target_index])
            left_target_index--;
        
        while(right_target_index + 1 <= nums.size() - 1 && nums[left_target_index] == nums[right_target_index + 1]) 
            right_target_index++;
        
        return vector<int>{left_target_index, right_target_index};
    }
};
