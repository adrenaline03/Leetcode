class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        } 

        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i < words.size(); i++) {
            if(isPalindrome(words[i])) {
                return words[i];
            }
        }

        return "";
    }
};