class MyHashMap {
private:
    static const int SIZE = 1000;
    vector<vector<pair<int,int>>> table;

public:
    MyHashMap() {
        table.resize(SIZE);
    }
    
    void put(int key, int value) {
        int idx = key % SIZE;

        for (auto &p : table[idx]) {
            if (p.first == key) {
                p.second = value;   // update
                return;
            }
        }

        table[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = key % SIZE;

        for (auto &p : table[idx]) {
            if (p.first == key) {
                return p.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int idx = key % SIZE;

        for (int i = 0; i < table[idx].size(); i++) {
            if (table[idx][i].first == key) {
                table[idx].erase(table[idx].begin() + i);
                return;
            }
        }
    }
};
