struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k, int v) {
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    int size, curr = 0;
    unordered_map<int, Node*> mpp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        size = capacity;
    }

    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            mpp[key]->prev->next = mpp[key]->next;
            mpp[key]->next->prev = mpp[key]->prev;
            mpp[key]->next = tail;
            mpp[key]->prev = tail->prev;
            tail->prev->next = mpp[key];
            tail->prev = mpp[key];
            return mpp[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            mpp[key]->prev->next = mpp[key]->next;
            mpp[key]->next->prev = mpp[key]->prev;
            mpp[key]->next = tail;
            mpp[key]->prev = tail->prev;
            tail->prev->next = mpp[key];
            tail->prev = mpp[key];
            mpp[key]->val = value;
            return;
        }
        if (curr == size) {
            mpp.erase(head->next->key);
            Node* first = head->next;
            head->next = first->next;
            first->next->prev = head;
            curr--;
            delete first;
        }
        Node* newNode = new Node(key, value);
        tail->prev->next = newNode;
        newNode->prev = tail->prev;
        tail->prev = newNode;
        newNode->next = tail;
        mpp[key] = newNode;
        curr++;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */