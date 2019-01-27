/** Simple solution, but was too lazy to think that day for some reason.
**/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_map;
        
        for(auto str : strs) {
            string anag_word = str;
            sort(anag_word.begin(), anag_word.end());
            hash_map[anag_word].push_back(str);
        }
        
        vector<vector<string>> ans;
        
        for(auto map_entry : hash_map) {
            vector<string> anagram_vector(map_entry.second.begin(), map_entry.second.end());
            ans.push_back(anagram_vector);
        }
        
        return ans;
    }
};
