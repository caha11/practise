/*  Easy problem, high acceptance rate. Just reminded me of using unordered_set
    for these types of problems. Using Vim now, seems like a better editor :)
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if(J.length() == 0 || S.length() == 0) return 0;
        
        unordered_set<char> jewelSet;
        int ans = 0;
        
        //Add jewels to a set
        for(int i = 0; i < J.length(); i++) {
            jewelSet.insert(J[i]);
        }
        
        //Check set for the occurance
        for(int i = 0; i < S.length(); i++) {
            if(jewelSet.find(S[i]) != jewelSet.end()) ans++;
        }
        
        return ans;
    }
};
