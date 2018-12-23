/** First approach was taking a very long time. Had to look at the answer. The solution is VERY simple and easy to understand. Maybe
	next time try to think of the solution a bit longer before commencing implementation. Think more.
**/

class Solution {
public:
    string intToRoman(int num) {

        vector<int> numbers = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> chars = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans = "";
        
        for(int i = 0; i < numbers.size(); i++) {
            while(num >= numbers[i]) {
                num -= numbers[i];
                ans += chars[i];
            }
        }
        
        return ans;
    }
};
