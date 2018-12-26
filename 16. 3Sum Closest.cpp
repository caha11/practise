/** Basically the same as previous, the same concept. So it was pretty easy
	to do.
**/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int ans = 0;
        int min_dist = INT_MAX;
        
        if(nums.size() < 3) return ans;
        if(nums.size() == 3) return nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < nums.size(); i++) {
            int start = i + 1, end = nums.size() - 1;
            while(start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == target) return target;
                else if(sum > target){
                    if(min_dist > abs(sum - target)) {
                        ans = sum;
                        min_dist = abs(sum - target);
                    }
                    end--;
                } else {
                    if(min_dist > abs(sum - target)) {
                        ans = sum;
                        min_dist = abs(sum - target);
                    }
                    start++; 
                }
            }
        }
        return ans;
    }
};
