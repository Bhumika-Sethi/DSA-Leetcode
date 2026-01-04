    class Node{
     public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(){
            prev = NULL;
            next = NULL;
        }
        Node(int keyy, int value){
            key = keyy;
            val = value;
            next = NULL;
            prev = NULL;
        }
    };
class LRUCache {
public:
    Node* head;
    Node* tail;
    map<int,Node*> locator;
    int cap;
    int cnt = 0;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        head->prev = NULL;
        tail->prev = head;
        tail->next = NULL;
    }
    
    int get(int key) {
        if(cap==0){
            return -1;
        }
        if(locator.find(key)!=locator.end()){
            Node* requiredNode = locator[key];
            int value = requiredNode->val;
            Node* previousNode = requiredNode->prev;
            Node* nextNode = requiredNode->next;
            previousNode->next = nextNode;
            nextNode->prev = previousNode;
            Node* newNext = head->next;
            head->next = requiredNode;
            requiredNode->prev = head;
            requiredNode->next = newNext;
            newNext->prev = requiredNode;
            return value;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cap==0){
            return;
        }
        if(locator.find(key)!=locator.end()){
            Node* requiredNode = locator[key];
            requiredNode->val = value;
            Node* previousNode = requiredNode->prev;
            Node* nextNode = requiredNode->next;
            previousNode->next = nextNode;
            nextNode->prev = previousNode;
            Node* newNext = head->next;
            newNext->prev = requiredNode;
            requiredNode->next = newNext;
            requiredNode->prev = head;
            head->next = requiredNode;
        }
        else{
            Node* newNode = new Node(key,value);
            locator[key] = newNode;
            Node* newNext = head->next;
            newNode->next = newNext;
            newNode->prev = head;
            newNext->prev = newNode;
            head->next = newNode;
            cnt++;
            if(cnt>cap){
                Node* toBeRemoved = tail->prev;
                Node* prevNode = toBeRemoved->prev;
                prevNode->next = tail;
                tail->prev = prevNode;
                cnt--;
                locator.erase(toBeRemoved->key);
                delete toBeRemoved;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */