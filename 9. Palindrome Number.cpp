/* Seems to be slow in comparison to others
*/


class Solution {
public:
    bool isPalindrome(int x) {
        string xString = to_string(x);
        int iterations = xString.length() / 2;
        bool isPalin = true;
        
        for(int i = 0; i < iterations; i++) {
            if(xString[i] != xString[xString.length() - 1 - i]) return false;
        }
        return true;
    }
};
