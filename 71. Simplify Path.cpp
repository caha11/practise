/** May need to work on it more in the future. Seems like a decent
	solution.
**/

class Solution {
public:
    string simplifyPath(string path) {
        if(!path.size()) return "";
        
        int size = path.size();
        int last_idx = path.size() - 1;
        string string_builder = "";
        string ans = "";
        vector<int> idx_array;
        idx_array.push_back(1);
        
        for(size_t i = 1; i < size; i++) {
            
            if(path[i] == '/' || i == last_idx) {
                
                // if the last index doesn't have a '/'
                if(i == last_idx && path[last_idx] != '/') {
                    string_builder += path[last_idx];
                }
                
                // Delete last part of path.
                if(string_builder == "..") {
                    ans = ans.substr(0, idx_array.back());
                    if(idx_array.size() > 1) idx_array.pop_back();
                    string_builder = "";
                }
                
                // Continue
                else if(string_builder == ".") {
                    string_builder = "";
                
                // Just append the name of the path.
                } else {
                    if(string_builder == "") continue;
                    idx_array.push_back(ans.size());
                    ans += '/' + string_builder;
                    string_builder = "";
                }
            // Otherwise just keep building.
            } else {
                string_builder += path[i];
            }
        }
        
        if(!ans.size()) return "/";
        
        return ans;
        
    }
};
