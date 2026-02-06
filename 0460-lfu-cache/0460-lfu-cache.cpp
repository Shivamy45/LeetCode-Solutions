struct Node {
    int key, val, freq;
    Node *prev, *next;
    Node(int k, int v)
        : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
};

struct DLL {
    Node *head, *tail;
    DLL() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addBack(Node* node) {
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    bool empty() { return head->next == tail; }

    Node* popFront() {
        Node* node = head->next;
        remove(node);
        return node;
    }
};

class LFUCache {
public:
    int capacity, used = 0, minFreq = 0;
    unordered_map<int, Node*> nodes;
    unordered_map<int, DLL*> freqList;

    LFUCache(int cap) : capacity(cap) {}

    DLL* getList(int f) {
        if (!freqList.count(f))
            freqList[f] = new DLL();
        return freqList[f];
    }

    void touch(Node* node) {
        int f = node->freq;
        freqList[f]->remove(node);
        if (f == minFreq && freqList[f]->empty())
            minFreq++;

        node->freq++;
        getList(node->freq)->addBack(node);
    }

    int get(int key) {
        if (!nodes.count(key))
            return -1;
        Node* node = nodes[key];
        touch(node);
        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (nodes.count(key)) {
            Node* node = nodes[key];
            node->val = value;
            touch(node);
            return;
        }

        if (used == capacity) {
            Node* victim = freqList[minFreq]->popFront();
            nodes.erase(victim->key);
            delete victim;
            used--;
        }

        Node* node = new Node(key, value);
        nodes[key] = node;
        minFreq = 1;
        getList(1)->addBack(node);
        used++;
    }
};