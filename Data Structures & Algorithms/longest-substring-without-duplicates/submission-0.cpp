class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> t;
        int maxLen = 0;
        int i = 0;

        for(int j = 0; j < s.size(); j++) {
            while(t.count(s[j])) {
                t.erase(s[i]);
                i++;
            }

            t.insert(s[j]);
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};
