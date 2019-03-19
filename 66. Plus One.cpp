/** Did this problem before, it's alright.

**/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        
        int carry = 1;
        int last = digits.size() - 1;
        int num = 0;
        while(carry) {
            if(last < 0) {
                ans.push_back(1);
                break;
            }
            num = (digits[last] + carry) % 10;
            carry = (digits[last] + 1) / 10;
            //cout << num << endl;
            ans.push_back(num);
            last--;
        }
        
        while(last >= 0) {
            ans.push_back(digits[last]);
            last--;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
