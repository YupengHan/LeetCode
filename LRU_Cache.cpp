class Dll {
public:
    int key;
    int val;
    Dll *next;
    Dll *prev;

    Dll(int key, int val) {
        this->key = key;
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
    Dll() {
        this->key = -1;
        this->val = -1;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
class LRUCache {
    
private:
    int max_capacity = 0;
    int cur_capacity = 0;
    unordered_map<int, Dll*> um;
    Dll *head, *tail;


public:
    LRUCache(int capacity) {
        max_capacity = capacity;
        head = new Dll();
        tail = new Dll();
        head->next = tail;
        tail->prev = head;
        
    }
    
    int get(int key) {
        if (um.find(key) == um.end()) { // never seen this before
            return -1;
        }

        Dll *dll = um[key];
        int value = dll->val;
        
        erasedll(dll);
        adddll(key, value);
        // cout << key << endl;
        return dll->val;
        
    }
    
    void put(int key, int value) {
        if (um.find(key) != um.end()) {
            cur_capacity--;
            Dll *cur_dll = um[key];
            um.erase(key);
            erasedll(cur_dll);
        }
        if (cur_capacity == max_capacity) {
            //cout << key << " " << value << " "<< "meet max" << endl;
            um.erase(tail->prev->key);
            erasedll(tail->prev);
            cur_capacity--;
        }
        adddll(key,value);
        cur_capacity++;
        // cout << key << endl;
    }

    void erasedll(Dll *dll) {
        dll->next->prev = dll->prev;
        dll->prev->next = dll->next;
        um.erase(dll->key);
        //cout << "erase" << dll->key << endl;
    }

    void adddll(int key, int val) {
        Dll * dll = new Dll(key,val);
        dll->next = head->next;
        dll->prev = head;
        head->next->prev = dll;
        head->next = dll;
        um[key] = dll;
        //cout << "add" << key << endl;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */