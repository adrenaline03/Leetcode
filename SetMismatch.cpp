class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> map;
        for(int i = 1; i <= n; i++) map[i]++;

        for(auto i: nums) map[i]--;

        int duplicate = 0, missing = 0;

        for(auto i: map) {
            if(i.second == -1) duplicate = i.first;
            if(i.second == 1) missing = i.first;
        }

        return {duplicate, missing};
    }
};