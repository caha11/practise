/** Pretty easy problem.
**/

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        string ans = "";
        while(s[s.length() - 1] == ' ') s.pop_back();
        
        int i = s.length() - 1;
        while(s[i] != ' ' && i >= 0) {
            ans += s[i];
            i--;
        }
        return ans.size();
    }
};
