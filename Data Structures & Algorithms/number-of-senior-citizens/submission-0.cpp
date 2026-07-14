class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (const string& d : details) {
            int age = (d[11] - '0') * 10 + (d[12] - '0');
            if (age > 60) count++;
        }
        return count;
    }
};