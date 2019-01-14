/** Was an okay problem, just need to learn how to add chars to a string.
	It causes a lot of errors. Learned to use string() when adding chars.
**/

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1; i < n; i++) {
            int count = 1;
            
            // Check if the size is 1
            if(ans.length() == 1)  {
                ans = string() + '1' + ans[0];
                continue;
            }
            
            // Make new string for contruction.
            string current_string = "";
            
            // Check and count repeating characters.
            for(int j = 0; j < ans.length() - 1; j++) {
                if(ans[j] == ans[j + 1]) count++;
                else {
                    current_string += to_string(count) + ans[j];
                    count = 1;
                }
            }
            
            // Add the remaining digits
            if(ans[ans.length() - 1] != ans[ans.length() - 2])
                current_string += string() + '1' + ans[ans.length() - 1];
            
            else current_string += to_string(count) + ans[ans.length() - 1];

            // Set the constructed string as ans, to repeat the loop.
            ans = current_string;
        }
            
        return ans;
    }
};
