/** Good approach, just needed to optimise more.
**/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        int n = nums.size();
        
        if(n < 4) return answer;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 3; i++) {
            // Check if it's a repeating 'i'
            if(i>0&&nums[i]==nums[i-1]) continue;
			// Check if the min sum is higher than the target.
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
			// Check if the max sum is lower than the target.
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            
            
            for(int j = i + 1; j < nums.size() - 2; j++) {
                // Check if it's a repeating 'j'.
                if(j>i+1&&nums[j]==nums[j-1]) continue;
				// Check if min with current 'j' and 'i' is higher than the target.
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
				// Check if max with current 'j' and 'i' is lower than the target.
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                
                int start = j + 1;
                int end = n - 1;
                
                while(start < end) {
                    int sum = nums[i] + nums[j] + nums[start] + nums[end];
                    if(sum < target) start++;
                    else if (sum > target) end--;
                    else {
                        answer.push_back(vector<int>{nums[i], nums[j], nums[start], nums[end]});
                        do {start++;}while(nums[start] == nums[start - 1] && start < end);
                        do {end--;}while(nums[end] == nums[end + 1] && start < end);
                    }
                }
            }
        }
        
        return answer;
    }
};
