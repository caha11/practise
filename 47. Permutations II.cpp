/** Still need practise on backtracking.

**/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        //sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        backtrack(ans, nums, 0);
        
        return ans;
    }
    
private:
    void backtrack(vector<vector<int>> &ans, vector<int> &nums, int position) {
        
        if(position >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for(int i = position; i < nums.size(); i++) {
  			// Checks if the digits are not the same
			// But allow when i and position to be the same          
            if((nums[i]!=nums[position] || i == position) && checkmiddle(nums,i,position)) {
            
                swap(nums[position], nums[i]);

                backtrack(ans, nums, position + 1);

                swap(nums[position], nums[i]);
            }
        }
    }
    
    // Basically check if this digit occured before, which indicates that the swap has been done already.
    bool checkmiddle(vector<int>& nums, int i , int begin){
        for(int k = begin; k<i; k++)
            if(nums[i] == nums[k])
                return false;
        return true;
    }
};
