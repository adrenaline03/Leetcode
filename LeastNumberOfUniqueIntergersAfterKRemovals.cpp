class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        int answer = 0;

        for(auto i: arr) m[i]++;

        vector<int> freq;
        for(auto i: m) freq.push_back(i.second);

        sort(freq.begin(), freq.end());

        int count = 0;
        for(int i = 0; i < freq.size(); i++) {
            count += freq[i];
            if(count > k) return freq.size() - i;
        }

        return 0;
    }
};