/** Simple problem. My own solution but it could be done with dynamic programming, or with a simpler for loop.
**/


class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == 0) {                
                
                int j = i - 1;
                
                while(i + 1 != nums.size() - 1 && nums[i + 1] == 0) i++;
                
                bool jumpOver = false;
                while(j >= 0) {
                    if(j + nums[j] > i) { jumpOver = true; break;}
                    j--;
                }
                if(!jumpOver) return 0;
            }
        }
        return 1;
    }
};
