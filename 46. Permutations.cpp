/** Had to look for the solution, a bit rusty on backtracking. Very
	confusing technique due to the recursion.
**/

class Solution {
public:
    vector<vector<int>> permute(vector<int> &num) {
	    vector<vector<int>> ans;
	    
	    backtrack(ans, num, 0);
	    return ans;
    }
    
private:
    void backtrack(vector<vector<int>> &ans, vector<int> &num, int position)
    {
        // If position is above the last index, then the permutation is complete.
        if(position >= num.size()) {
            ans.push_back(num);
            return;
        }
        
        for(int i = position; i < num.size(); i++) {
            swap(num[position], num[i]);
            
            for(int j = 0; j < num.size(); j++) {
                cout << num[j] << " ";
            }
            cout << "  Pos: " << position << "  Ind: " << i << endl;
            
            backtrack(ans, num, position + 1);
            
            // Swap back, so that future swaps are uneffected.
            swap(num[position], num[i]);
        }
    }
};
