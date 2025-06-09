// https://neetcode.io/problems/lru-cache?list=blind75

class LRUCache {
    int cap;
    map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
public:
    LRUCache(int capacity):cap(capacity) {
        
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end())
            return -1;
        auto val = it->second.first;
        order.erase(it->second.second);
        order.push_back(key);
        cache[key].second = --order.end();
        return val;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it != cache.end()) // cache hit
        {
            order.erase(cache[key].second);
        } 
        else if(cap == cache.size())
        {
            auto k = order.front();
            order.pop_front();
            cache.erase(k);
        }

        order.push_back(key);
        //pair<int, list<int>::iterator>> tmp = {value, --order.end()};
        cache[key] = {value, --order.end()};
    }
};
