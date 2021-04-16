class Node {
public:
    int key;
    int val;

    Node* prev;
    Node* next;

    Node(int _key, int _val) {
        this->val = _val;
        this->key = _key;
        this->prev = nullptr;
        this->next = nullptr;
    }
    // Node(int _key, int _val, Node* _prev, Node* _next) {
    //     this->val = _val;
    //     this->prev = _prev;
    //     this->next = _next;
    // }
};

class LRUCache {
private:
    Node* dummy;
    int cap;
    int cNum;
    unordered_map<int, Node*> myHash;
    Node* tail;
public:
    LRUCache(int capacity) {
        dummy = new Node(0, 0);
        cap = capacity;
        cNum = 0;
        tail = dummy;
    }
    
    int get(int key) {
        // move item
        if (!myHash.count(key)) {
            return -1;
        }
        else {
            //update to head
            if (dummy->next != nullptr) {
                // cout << dummy->val <<endl;
                dummy->next->prev = nNode;
                nNode->next = dummy->next;
                dummy->prev = nNode;
            }
            else {
                dummy->next = nNode;
                nNode->prev = dummy;
                tail = nNode;
            }
            return myHash[key]->val;
        }
    }
    
    void put(int key, int value) {
        if (!myHash.count(key)) {
            cNum++;
            Node* nNode = new Node(key, value);
            // do sth // insert to head;
            if (dummy->next != nullptr) {
                // cout << dummy->val <<endl;
                dummy->next->prev = nNode;
                nNode->next = dummy->next;
                dummy->prev = nNode;
            }
            else {
                dummy->next = nNode;
                nNode->prev = dummy;
                tail = nNode;
            }


            if (cNum > cap) {
                // erase from Hash
                myHash.erase(tail->key);
                // delete tail!
                tail->prev->next = nullptr;
                Node* oldtail = tail;
                delete oldtail;
                tail = tail->prev;
                cNum--;
                
            }
            // myHash.emplace({key, nNode})
            myHash[key] = nNode;
        }
        else {
            
            Node* nNode = new Node(key, value);
            // do sth // insert to head;
            if (dummy->next) {
                dummy->next->prev = nNode;
                nNode->next = dummy->next;
                dummy->prev = nNode;
            }
            else {
                dummy->next = nNode;
                nNode->prev = dummy;
                tail = nNode;
            }
            // move item
            Node* dNode = myHash[key];
            dNode->prev->next = dNode->next;
            if (dNode->next) {
                dNode->next->prev = dNode->prev;
            }
            delete dNode;
            //update Hash
            myHash[key] = dummy->next;
        }
        
    }


};