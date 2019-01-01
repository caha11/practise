/** Still shaky on how it works.
**/

class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.empty()) return "";
        if(s.length() == 1) return s;
        
        int max_length = 1, start_index = 0;
        
        for(int i = 0; i < s.length();) {
            // If max string possible is lower than max length - break.
            if (s.size() - i <= max_length / 2) break;

            // Skip repeating letters
            int right = i, left = i;
            while(right < s.length() - 1 && s[right] == s[right + 1]) right++;
            i = right + 1;
			
			// Check left and right.            
            while(left > 0 && right < s.length() - 1 && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }
            int string_length = right - left + 1;
            if(max_length < right - left + 1) {
                max_length = string_length;
                start_index = left;
            }
        }
        return s.substr(start_index, max_length);
    }
};
