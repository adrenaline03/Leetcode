class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> m(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        for(int i = 0; i <= nums.size(); i++) {
            if(m[i] == 0) return i;
        }

        return 1;
    }
};