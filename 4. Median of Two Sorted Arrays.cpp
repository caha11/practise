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

/** Better solution, (looked at the answers, probably wouldn't think of it. Took
a while to understand, but got it in the end I guess.
**/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if(m > n) {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            int tempN = m;
            m = n;
            n = tempN;
        }
        
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        
        while(iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            
            if(i < iMax && nums2[j - 1] > nums1[i]) {
                iMin = i + 1;
            } else if(i > iMin && nums1[i - 1] > nums2[j]) {
                iMax = i - 1;
            } else {
                int maxLeft = 0;
                if(i == 0) maxLeft = nums2[j - 1];
                else if (j == 0) maxLeft = nums1[i - 1];
                else maxLeft = max(nums1[i - 1], nums2[j - 1]);
                
                if((m + n) % 2 == 1) return maxLeft;
                
                int minRight = 0;
                if(i == m) minRight = nums2[j];
                else if(j == n) minRight = nums1[i];
                else minRight = min(nums2[j], nums1[i]);
                
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
}; 
