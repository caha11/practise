/**
    Thought it was a math problem, but no it's just about tracking the row and direction. It's
    all about storing strings for each row in a vector. Pretty easy problem actually, I was just
    thinking how to do it mathematically
**/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        vector<string> rows(min(numRows, int(s.length())));
        
        int currRow = 0;
        bool direction = false;
        
        for(char c : s) {
            rows[currRow] += c;
            if(currRow == 0 || currRow == numRows - 1) direction = !direction;
            
            currRow += direction ? 1 : -1;
        }
        
        string ans = "";
        for(string rowsString : rows) {
            ans += rowsString;
        }
        
        return ans;
    }
};
