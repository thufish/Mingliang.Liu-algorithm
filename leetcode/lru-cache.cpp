struct CacheItem {
    CacheItem *prev;
    CacheItem *next;
    int key;
    int val;
    
    CacheItem(int key, int val) : key(key), val(val) {
        prev = next = this;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        head = nullptr;
        this->capacity = capacity;
        count = 0;
    }
    
    int get(int key) {
        if (C.find(key) != C.end()) {
            CacheItem *ci = C[key];
            moveToHead(ci);
            return ci->val;
        } else
            return -1;
    }
    
    void set(int key, int value) {
        if (C.find(key) == C.end()) {  // insert
            CacheItem *ci = new CacheItem(key, value);
            C[key] = ci;
            
            // find the victim to replace
            if (count == capacity) {
                CacheItem *vi = head->prev;
                vi->prev->next = head;
                head->prev = vi->prev;
                C.erase(vi->key);
                if (vi == head)
                    head = nullptr;
                delete vi;
            } else
                count++;
                
            if (head) {
                ci->next = head;
                ci->prev = head->prev;
                head->prev->next = ci;
                head->prev = ci;
            }
            head = ci;
        } else { // update
            CacheItem *ci = C[key];
            moveToHead(ci);
            ci->val = value;
        }
    }

private:
    void moveToHead(CacheItem *ci) {
        if (ci == nullptr || ci == head)
            return;

        ci->prev->next = ci->next;
        ci->next->prev = ci->prev;
        if (head) {
            ci->prev = head->prev;
            ci->next = head;
            head->prev->next = ci;
            head->prev = ci;
        }

        head = ci;
    }

private:
    unordered_map<int, CacheItem *> C;
    CacheItem *head;
    int capacity;
    int count;
};
