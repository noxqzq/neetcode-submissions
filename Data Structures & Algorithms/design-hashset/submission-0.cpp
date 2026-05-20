class MyHashSet {
private:
    int bucketCount;
    vector<vector<int>> buckets;

public:
    MyHashSet() {
        bucketCount = 1000;
        buckets.resize(bucketCount);
    }
        
    void add(int key) {
        //compute bucket index
        int index = key % bucketCount;

        //get a reference to the correct bucket
        vector<int>& bucket = buckets[index];

        //check if key already exists
        for (int val : bucket) {
            if (val == key)
                return;  // already in the set
        }

        //key not found then insert
        bucket.push_back(key);
    }
    
    void remove(int key) {
        //compute bucket index
        int index = key % bucketCount;

        //get a reference to the correct bucket
        vector<int>& bucket = buckets[index];

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] == key) {
                bucket.erase(bucket.begin() + i);
                return; // key removed, done
            }
        }
    }
    
    bool contains(int key) {
        //compute bucket index
        int index = key % bucketCount;

        //get a reference to the correct bucket
        vector<int>& bucket = buckets[index];

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] == key) {
                return true; // key removed, done
            }
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */