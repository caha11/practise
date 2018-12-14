/* The trick is to use an hash map which is the unordered map in c++. So it's pretty straightforward afterwards.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            int complementary = target - nums[i];
            if(hash_map.find(complementary) != hash_map.end()) {
                ans.push_back(i);
                ans.push_back(hash_map.find(complementary)->second);
                return ans;
            } else {
                hash_map.insert(std::make_pair(nums[i], i));
            }
        }
        
        return ans;
    }
};