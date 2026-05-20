class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<string> sorted(n);
        for (int i = 0; i < n; i++) {
            sorted[i] = strs[i];
            sort(sorted[i].begin(), sorted[i].end());
        }

        vector<bool> used(n, false);
        vector<vector<string>> anas;

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;

            vector<string> group;
            group.push_back(strs[i]);
            used[i] = true;

            for (int j = i + 1; j < n; j++) {
                if (used[j]) continue;

                if (sorted[i] == sorted[j]) {
                    group.push_back(strs[j]);
                    used[j] = true;
                }
            }

            anas.push_back(group);
        }

        return anas;
    }
};
