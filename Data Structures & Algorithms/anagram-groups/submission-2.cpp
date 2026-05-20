class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anas(strs.size());
        vector<bool> used(strs.size(), false);

        for (int i = 0; i < strs.size(); i++) {
            if (used[i]) continue;

            string s = strs[i];
            sort(s.begin(), s.end());

            anas[i].push_back(strs[i]);
            used[i] = true;

            for (int j = i + 1; j < strs.size(); j++) {
                if (used[j]) continue;

                string t = strs[j];
                sort(t.begin(), t.end());

                if (s == t) {
                    anas[i].push_back(strs[j]);
                    used[j] = true;
                }
            }
        }
        
        vector<vector<string>> result;
        for (auto& v : anas) {
            if (!v.empty()) {
                result.push_back(v);
            }
        }

        return result;
    }
};
