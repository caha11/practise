/** Solution wasn't that hard, I was sort of on the right track. Gave up a bit fast and looked at the answer.
	The problem I could probably come up with. Try to think longer.
**/

class Solution {
public:
	vector<vector<int>> threeSum(<vector<int> &nums) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size(); i++) {
			if((i > 0) && (nums[i] == nums[i + 1])) continue;
				
			int front = i + 1;
			int back = nums.size() - 1;

			while(front < back) {
				int sum = nums[i] + nums[start] + nums[end];
				if(sum == 0) {
					ans.push_back(vector<int>{nums[i], nums[start], nums[back])};
					while(nums[start] == nums[start + 1]) start++;
					while(nums[end] == nums[end - 1]) end--;	
					front++;
					back--;
				}
				else if(sum < 0) front++;
				else back ++;
			}
		}
		return ans;
	}
}
