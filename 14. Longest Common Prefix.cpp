/** Took a bit long to code, knew the solution though. Easy problem. Didn't add the return. NEED TO ACCOUNT FOR EDGE CASES.
**/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = "";
        if(strs.size() == 0) return ans;
        if(strs.size() == 1) return strs[0];
        for(auto word : strs) {
            if(word == "") return ans;
        }
        
        for(int i = 0; i < strs[0].length(); i++) {
            char currC = strs[0][i];
            for(int j = 1; j < strs.size(); j++) {
                if(strs[j].length() == i) return ans;
                if(strs[j][i] != currC) return ans;
            }
            ans += currC;
        }
        return ans;
    }
};
