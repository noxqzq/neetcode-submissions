class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;

        for (const string& op : ops) {
            if (op == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top();
                st.push(top1);              // put it back
                st.push(top1 + top2);       // push new score
            }
            else if (op == "D") {
                st.push(2 * st.top());
            }
            else if (op == "C") {
                st.pop();
            }
            else {
                st.push(stoi(op));
            }
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};