/** Bit manipulation problem. Looked at my old book on it. An ok solution.

	Good: Still remember a lot about bit manipulation.

	Bad : Needed to look at the answer. Probably could've solved it myself if I was more persistent.
**/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Check if divisor is not 0, and check if dividend is INT_MIN and devisor is -1.
        // Because that combination will overflow.
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        
        // Bit operations are good for positive ints. So we need to memorise the sign.
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        
        // Make sure that both nums are positive.
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        
        
        while (dvd >= dvs) { 
            long long temp = dvs, multiple = 1;
            
            // Finding multiples of 2*divisor that will fit into the dividend.
            // Multiply the divisor * 2 as much as possible so that it is still be lower than  the divisor.
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            
            // Subtract the largest divisor that was multiplied by 2.
            // Add the multiples of 2 into the result.
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res; 
    }
};
