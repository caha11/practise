/* Easy problem but didn't think hard enough. */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        if(nums.size() <= 1) return;
        
        int front = 0;
        int curr = 0;
        int last = nums.size() - 1;
        
        while(curr <= last) {
            
            if(nums[curr] == 2) swap(nums[curr], nums[last--]);
            else if(nums[curr] == 0) {
                swap(nums[curr++], nums[front++]);
            } else curr++;
        }
    }
};
