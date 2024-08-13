// ---------------------------- Approach - 1 --------------------------
// Using Vector (TLE)

class LRUCache {
public:
    vector<pair<int, int>> cache;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        for(int i = 0; i < cache.size(); i++){
            if(cache[i].first == key){
                int val = cache[i].second;

                pair<int, int> temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);

                return val;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i = 0; i < cache.size(); i++){
            if(cache[i].first == key){
                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                return;
            }
        }
        if(cache.size() == n){
            cache.erase(cache.begin());
            cache.push_back({key, value});
        } else {
            cache.push_back({key, value});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 // ---------------------------- Approach - 2 --------------------------
// Optimal

class LRUCache {
public:
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> mp;

    int n;

    LRUCache(int capacity) {
        n = capacity;
    }

    void makeRecentlyUsed(int key){
        dll.erase(mp[key].first);

        dll.push_front(key);

        mp[key].first = dll.begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        makeRecentlyUsed(key);

        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makeRecentlyUsed(key);
        } else{
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        if(n < 0){
            int key_tobe_del = dll.back();
            mp.erase(key_tobe_del);

            dll.pop_back();

            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */