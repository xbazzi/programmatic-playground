class MyHashSet {
public:
    
    MyHashSet() {
    }
    
    void add(int key) {
        if(!this->contains(key)) set.push_back(key);
    }
    
    void remove(int key) {
        if (set.size() == 0) return;
        for (auto it = set.begin(); it != set.end(); it++) {
            if (*it == key) {
                set.erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        //if (set.size() == 0) return false;
        for (auto it = set.begin(); it != set.end(); it++) {
            if (*it == key) {
                return true;
            }
        }
        return false;
    }
    
    std::vector<int> set;
};