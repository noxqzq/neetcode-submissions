class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string prefix;
        const string& base = strs[0];

        for (int i = 0; i < (int)base.size(); i++) {
            char ch = base[i];

            for (int j = 1; j < (int)strs.size(); j++) {
                if (i >= (int)strs[j].size() || strs[j][i] != ch) {
                    return prefix;
                }
            }
            prefix.push_back(ch);
        }
        return prefix;
    }
};