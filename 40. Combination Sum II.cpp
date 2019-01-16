/** Builds on the same principles as 39. but with a small twist.
**/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        // Sort first.
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        
        backtrack(candidates, ans, curr, target, 0);
        
        return ans;
    }
    
private:
    void backtrack(vector<int> candidates, 
                   vector<vector<int>> &ans,
                   vector<int> &curr,
                   int target, 
                   int position)
    {
        if(target == 0) {
            ans.push_back(curr);   
            return;
        }
        
        
        for(int i = position; i < candidates.size(); i++) {
            if(candidates[i] > target) break;
            //if(i != 0 && candidates[i] == candidates[i-1] && candidates[position] == candidates[i]) continue;
            
            curr.push_back(candidates[i]);
            
            backtrack(candidates, ans, curr, target - candidates[i], i + 1);
            
            curr.pop_back();
            
            // Do it at the end to ensure that it iterates through duplicates at least once.
            // And then shift i, to ensure that there are no duplicate pairs.
            while(i < candidates.size() && candidates[i] == candidates[i + 1]) i++;
        }
        
    }
};
