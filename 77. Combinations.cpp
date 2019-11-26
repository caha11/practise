/** Easy problem, just takes a while to understand backtracking algorithm.
	Makes head hurt :(
**/ 


class Solution {
public:
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        backprop(ans, curr, 1, n, k, 0);
        
        return ans;
    }
    
    void backprop(vector<vector<int>> &ans, vector<int> &curr, int position, int n, int k, int j) {
        
        for(auto i : curr) {
            cout << position << " : " << 
        }
        
        if(j == k) {
            ans.push_back(curr);
            return;
        }
        
        for(int i = position; i <= n; i++) {
            curr.push_back(i);
            backprop(ans, curr, i + 1, n, k, j + 1);
            curr.pop_back();
        }
    }
};
