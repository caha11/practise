/** Backtracking problem. I haven't had much experience with this before.
	So it was nice to explore this problem. Had to use the solution for
	this.
**/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        
        // Current vector we are building.
        vector<int> curr;
        
        // Sort n log n.
        sort(candidates.begin(), candidates.end());
        
        // New backtracking technique I haven't considered before.
        backtrack(res, candidates, curr, target, 0);
        
        return res;
    }

private:
    void backtrack(vector<vector<int>>& res, 
                   const vector<int>& candidates,
                   vector<int>& curr,
                   int target,
                   int pos) {
        
        // If target is reached, push the answer.
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        
        // Iterate through remaining elements.
        for (size_t i = pos; i < candidates.size(); ++i) {
            // If above target, stop immediately.
            if (candidates[i] > target) {
                break;
            }
            
            // Add the candidate to the stack
            curr.push_back(candidates[i]);
            
            // Explore this path.
            backtrack(res, candidates, curr, target - candidates[i], i);
            
            // If the end of path was reached, but it didnt trigger the target == 0, then remove element.
            curr.pop_back();
        }
    }
};
