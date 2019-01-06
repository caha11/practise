/** Easy problem, just need to think about edge cases more.

	Good: Fast and quick solution.

	Bad : Didn't account for the needle length. If needle length is higher than the haystack, then return -1.
**/

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int ans = -1;
        if(haystack.empty() && needle.empty()) return 0;
        if(haystack.empty()) return ans;
        if(needle.empty()) return 0;
        
        if(needle.length() > haystack.length()) return ans;
        
        for(int i = 0; i < haystack.length() - needle.length() + 1; i++) {
            if(haystack[i] == needle[0]) {
                bool match_string = true;

                for(int j = 1; j < needle.length(); j++) {
                    if(haystack[i + j] != needle[j]) {
                        match_string = false;
                        break;
                    }
                }
                if(match_string) return i;
            }
        }
        return ans;  
    }
};
