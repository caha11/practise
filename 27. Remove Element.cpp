/* Easy solution, based on previous exercise. Nothing was learned here.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //int nums_size = nums.size();
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == val) count++;
            else nums[i - count] = nums[i];
        }
        return nums.size() - count;
    }
};
