/** Gave up too fast. Should've spent a bit more time. Not that hard of a
	problem.
**/

class Solution {
public:
    string multiply(string num1, string num2) 
    {
        
        vector<int> product(num1.length() + num2.length());
     
		// Reverse to make it easier to pop all the 0s afterwards.   
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        // Perform the product.
        for(int i = 0; i < num1.length(); i++) {
            for(int j = 0; j < num2.length(); j++) {
                product[i+j]   += (num1[i] - '0') * (num2[j] - '0'); // Product
                product[i+j+1] += product[i+j] / 10; // Add carry on to the next slot
                product[i+j]   %= 10; // Keep only the single digit
            }
        }
        
        int end = num1.length() + num2.length() - 1;
        
		// Delete all the zeros. 
        while(product[end] == 0 && product.size() > 1) {
            product.pop_back();
            end--;
        }
        
		// Convert vector to string.
        string ans = "";
        for(int i = end; i >= 0; i--) {
            ans += to_string(product[i]);
        }
        
        return ans;
    }
};
