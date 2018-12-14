/** Only works with alphabet characters in lower case. Doesn't work for other symbols.
 * That's why it fails when submitting the solution.
 * A better approach would be to use a set in that case.
**/

class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        
        bool track[26];
        int maxCount = 0;
        int currCount = 0;
        
        for(int i = 0; i < s.length(); i++) {
            char charOfStr = s[i];
            int charInt = (int)charOfStr - 97;
            cout << charOfStr << "Represents: " << charInt << endl;
            if(track[charInt] != 1) {
                track[charInt] = 1;
                cout << "Track is " << track[charInt] << endl; 
                currCount++;
            }
            else if(track[charInt] == 1 || i == (s.length() - 1)) {
                if(currCount >= maxCount) {
                    maxCount = currCount;
                }
                currCount = 1;
                for(int i = 0; i < 26; i++) {
                    track[i] = 0;
                    if(i == charInt) track[i] = 1;
                }
            }
        }
        return maxCount;
    }
};