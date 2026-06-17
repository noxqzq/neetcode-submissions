class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> pal;
        backtrack(s, 0, pal, res);
        return res;
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrack(const string& s, int start, vector<string>& pal, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(pal);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                pal.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, pal, res);
                pal.pop_back();
            }
        }
    }
};