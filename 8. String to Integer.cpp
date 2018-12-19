/** Low quality problem, weird behaviour with signs. Had the right approach though. Good solution.
    but bad execution.
**/

class Solution {
public:
    int myAtoi(string str) {
        if(str == "") return 0;
        long ans = 0;
        int counter = 0;
        
        while(str[counter] == ' ') {
            counter++;
        }
        
        int indicator = 1;
        if(str[counter] == '-' || str[counter] == '+') indicator = (str[counter++] == '-')? -1 : 1;
        
        while(int(str[counter]) >= 48 && int(str[counter]) <= 57 && counter < str.length()) {
            int digit = str[counter] - '0';
            ans = ans * 10 + digit;
            if(ans * indicator >= INT_MAX) return INT_MAX;
            if(ans * indicator <= INT_MIN) return INT_MIN;
            counter++;
        }
        return ans * indicator;
    }
};
