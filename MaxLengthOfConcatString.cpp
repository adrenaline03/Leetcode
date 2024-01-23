class Solution {
public:
    bool hasDuplicate(string& s1, string& s2) {
        int arr[26] = {0};

        for(char &ch: s1) {
            if(arr[ch - 'a'] > 0) return true;

            arr[ch - 'a']++;
        }

        for(char &ch: s2) {
            if(arr[ch - 'a'] > 0) return true;
        }

        return false;
    }

    int solve(int idx, vector<string>& arr, string temp, int n) {
        if(idx >= n) return temp.length();

        int take = 0, notTake = 0;

        if(hasDuplicate(arr[idx], temp)) {
            notTake = solve(idx+1, arr, temp, n);
        } else {
            notTake = solve(idx+1, arr, temp, n);
            take = solve(idx+1, arr, temp+arr[idx], n);
        }

        return max(take, notTake);
    }

    int maxLength(vector<string>& arr) {
        string temp = "";
        int n = arr.size();

        return solve(0, arr, temp, n);
    }
};