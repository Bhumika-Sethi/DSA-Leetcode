class LRUCache {
    class Node{
        public:
            int val;
            int key;
            Node* next;
            Node* prev;
        
            Node(int keyy, int value){
                key = keyy;
                val = value;
            }
    };
public:
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    map<int,Node*> mp;
    int cap = 0;
    
    
    void addNode(Node* to_be_added){
        Node* temp = head->next;
        to_be_added->next = temp;
        to_be_added->prev = head;
        
        head->next = to_be_added;
        temp->prev = to_be_added;
    }
    
    
    void deleteNode(Node* to_be_deleted){
        Node* prevNode = to_be_deleted->prev;
        Node* nextNode = to_be_deleted->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* resNode = mp[key];
            int res = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* to_be_deleted = mp[key];
            mp.erase(key);
            deleteNode(to_be_deleted);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* to_be_added = new Node(key,value);
        addNode(to_be_added);
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */