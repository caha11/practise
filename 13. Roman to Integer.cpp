/** Thought about the solution more, was able to get a decent solution. Good thing I thought about the problem a bit more. However, the
	speed is very slow. Could probably be improved with unordered_map instead of "if" statement nest.
**/

int strToNum(char c) {
    if(c == 'I') return 1;
    else if(c == 'V') return 5;
    else if(c == 'X') return 10;
    else if(c == 'L') return 50;
    else if(c == 'C') return 100;
    else if(c == 'D') return 500;
    else if(c == 'M') return 1000;
    else return 0;
}

class Solution {
public:
    int romanToInt(string s) {
        int last_num = 0;
        int current_num = 0;
        int ans = 0;
        
        for(int i = s.length() - 1; i >= 0; i--) {
            current_num = strToNum(s[i]);
            cout << current_num << " : " << last_num << endl;
            if(current_num < last_num) current_num *= -1;
            ans += current_num;
            last_num = current_num;
        }
        
        return ans;
    }
private: 
    int strToNum(char c) {
        if(c == 'I') return 1;
        else if(c == 'V') return 5;
        else if(c == 'X') return 10;
        else if(c == 'L') return 50;
        else if(c == 'C') return 100;
        else if(c == 'D') return 500;
        else if(c == 'M') return 1000;
        else return 0;
    }
};
