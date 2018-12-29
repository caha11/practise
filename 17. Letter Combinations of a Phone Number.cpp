/** The solution is straight forward. Just couldn't think of it for some reason. Basically keeps adding letters to string.
**/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return result;
        vector<string> loopUpArray = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        result.push_back("");
        
		// Basically, adding letters to the string, that were added.
		for(int i = 0; i < digits.length(); i++) {
            vector<string> tmp;
            int num = digits[i] - '0';
            const string &candidate = loopUpArray[num];
            
            for(int j = 0; j < candidate.size(); j++) {
                for(int k = 0; k < result.size(); k++) {
                    tmp.push_back(result[k] + candidate[j]);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};


