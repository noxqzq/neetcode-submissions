class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        backtrack(0, 0, n, cur, res);
        return res;
    }

    void backtrack(int openN, int closedN, int n, string& cur, vector<string>& res) {

        if (openN == n && closedN == n) {
            res.push_back(cur);
            return;
        }

        if (openN < n) {
            cur.push_back('(');
            backtrack(openN + 1, closedN, n, cur, res);
            cur.pop_back();
        }

        if (closedN < openN) {
            cur.push_back(')');
            backtrack(openN, closedN + 1, n, cur, res);
            cur.pop_back();
        }
    }
};