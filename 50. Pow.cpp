/**
	Pretty easy problem, but I'm not good at recursion still. Need more
	practise. Got the answer from a solution, but I understand it pretty
	well.
**/

class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) 1 / x * myPow(1/x, -(n+1));
        if(n == 0) return 1;
        if(n == 2) return x * x;
        if(n % 2 == 0) return myPow( myPow(x, n/2), 2);
        else if(n % 2 == 1) return x * myPow( myPow(x, n/2), 2);
    }
};
