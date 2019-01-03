/** Good learning experience. Didn't have much experience with recursion. Good start to
	learn recursion. I like it.
**/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        addParentheses(ans, "", n, 0);
        return ans;
    }
    
    void addParentheses(vector<string> &ans,
                        string par_string,
                        int open_num,
                        int close_num) {
        
        if(open_num == 0 && close_num == 0) {
            ans.push_back(par_string);
            return;
        }
        
        if(open_num  > 0) addParentheses(ans, par_string + "(", open_num - 1, close_num + 1);
        if(close_num > 0) addParentheses(ans, par_string + ")", open_num, close_num - 1);
    }                       
};

