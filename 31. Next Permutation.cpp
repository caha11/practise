/** Really didn't understand the problem. Never encountered 'lexicographic'
	order. Just keep this problem in mind, because if you don't know what
	what it's talking about, then you might be 'doomed'.

	The answer is not mine, it's from the forum. Basically the same logic 
	to the solution's. However, the solution's approach didn't work in C++
	for some reason.
**/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size(), k, l;
        
        // Finding when the num on the left decreases.
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
        // If not found, just reverse the array.
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
            
        // Otherwise, swap the element, and then reverse everything to the right.
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
}; 
