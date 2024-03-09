class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int first = 0;
        int second = 0;
        
        while (first < n && second < m) {
            if (nums1[first] == nums2[second]) {
                return nums1[first];
            } else if (nums1[first] < nums2[second]) {
                first++;
            } else
                second++;
        }

        return -1;
    }
};