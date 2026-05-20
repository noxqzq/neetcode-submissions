class Solution {
public:
    bool isPalindrome(string s) {
        string t;

        for(int i = 0; i < s.size(); i++) {
            if(isalnum(s[i])) {
                t += tolower(s[i]);
            }
        }

        for(int i = 0, j = t.size() - 1; i < j; i++, j--) {
            if(t[i] != t[j]) {
                return false;
            }
        }
        return true;
    }
};
