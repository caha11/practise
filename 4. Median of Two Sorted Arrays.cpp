/** Easy but very slow solution, didn't look at the answer, so it's good. A lot
    of mistakes coding thought, so it took a while bebugging. Need to make sure
    that I'm programming a bit cleaner.
**/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> wholeArray;
        int i = 0;
        int j = 0;
        
        while(j < nums2.size() || i < nums1.size()) {
            cout << "pos: " << i << " = " << j << endl;
            if(i == nums1.size()) {
                wholeArray.push_back(nums2[j]);
                j++;
            } else if(j == nums2.size()) {
                wholeArray.push_back(nums1[i]);
                i++;
            } else if(nums1[i] >= nums2[j]) {
                wholeArray.push_back(nums2[j]);
                j++;
            } else if(nums1[i] < nums2[j]) {
                wholeArray.push_back(nums1[i]);
                i++;
            }
        }
        
        for(int i = 0; i < wholeArray.size(); i++) {
            cout << wholeArray[i];
        }
        cout << endl;
        
        int middle = wholeArray.size() / 2;
        if(wholeArray.size() % 2 == 0) return (wholeArray[middle] + wholeArray[middle - 1]) / 2.0;
        else return wholeArray[middle];
    }
}; 
