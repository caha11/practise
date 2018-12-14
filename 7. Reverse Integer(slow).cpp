/* Very slow solution using strings, better way is introduced in solutions */

class Solution {
public:
    int reverse(int x) {
        string xString = to_string(x);
        double ans = 0;
        int stopLoop = 0;
        int firstZero = 1;
        
        if(xString[0] == '-') stopLoop = 1;
        
        for(int i = xString.length() - 1; i >= stopLoop; i--) {
            if(xString[i] == '0' && firstZero) continue;
            else {
                firstZero = 0;
                int multiplier = pow(10, i - stopLoop);
                int charToInt = int(xString[i]) - 48;
                cout << charToInt << endl;
                ans += (double)multiplier * charToInt;
            }
        }
        if(ans > INT_MAX) return 0;
        return stopLoop ? (int)ans * -1 : (int)ans;
    }
};