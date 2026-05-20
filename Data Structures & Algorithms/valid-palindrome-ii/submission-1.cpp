class Solution {
public:
    bool isPal(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                return isPal(s, i + 1, j) || isPal(s, i, j - 1);
            }
            i++;
            j--;
        }
        return true;
    }
};