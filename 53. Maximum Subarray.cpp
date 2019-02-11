/** I've done this before, so it was pretty easy for me **/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_num = INT_MIN;
        int sum = 0;
        for(int number : nums) {
            sum += number;
            max_num = max(max_num, sum);
            
            if(sum < 0) {
                sum = 0;
            }
        }
        return max_num;
    }
};
