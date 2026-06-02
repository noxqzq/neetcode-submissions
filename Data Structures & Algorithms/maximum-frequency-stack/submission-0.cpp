class FreqStack {
    unordered_map<int, int> cnt;
    vector<int> st;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        cnt[val]++;
    }
    
    int pop() {
        int maxCnt = 0;
        for(auto& [x, frequency] : cnt) {
            maxCnt = max(maxCnt, frequency);
        }
        int i = st.size() - 1;
        while (cnt[st[i]] != maxCnt) {
            i--;
        }
        int val = st[i];
        st.erase(st.begin() + i);
        cnt[val]--;
        return val;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */