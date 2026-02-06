struct LFUnode {
    int val, cnt, key;
    LFUnode* prev;
    LFUnode* next;
    LFUnode(int k, int v) {
        key = k;
        val = v;
        cnt = 1;
        prev = nullptr;
        next = nullptr;
    }
};

struct DLL {
    LFUnode* head;
    LFUnode* tail;
    DLL() {
        head = new LFUnode(-1, -1);
        tail = new LFUnode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
};

class LFUCache {
public:
    int size, currSize = 0, minFreq = 1;
    unordered_map<int, LFUnode*> keyNode;
    unordered_map<int, DLL*> freqNode;
    LFUCache(int capacity) { size = capacity; }

    int get(int key) {
        int val = -1;
        if (keyNode.find(key) != keyNode.end()) {
            // detach
            LFUnode* node = keyNode[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;
            // update freq
            if (minFreq == node->cnt &&
                freqNode[node->cnt]->head->next == freqNode[node->cnt]->tail)
                minFreq = node->cnt + 1;
            // increase cnt
            node->cnt++;
            if (!freqNode.count(node->cnt))
                freqNode[node->cnt] = new DLL();
            LFUnode* tail = freqNode[node->cnt]->tail;
            node->prev = tail->prev;
            tail->prev->next = node;
            node->next = tail;
            tail->prev = node;
            val = node->val;
        }
        return val;
    }

    void put(int key, int value) {
        LFUnode* node = nullptr;
        if (keyNode.find(key) != keyNode.end()) {
            node = keyNode[key];
            node->val = value;
            // detach
            node->prev->next = node->next;
            node->next->prev = node->prev;
            if (minFreq == node->cnt &&
                freqNode[node->cnt]->head->next == freqNode[node->cnt]->tail) {
                freqNode.erase(node->cnt);
                minFreq = node->cnt + 1;
            }
            // increase cnt
            node->cnt++;
        } else {
            // create new
            node = new LFUnode(key, value);

            // deletes lfu + lru
            if (currSize == size) {
                LFUnode* head = freqNode[minFreq]->head;
                LFUnode* old = head->next;
                old->next->prev = head;
                head->next = old->next;
                keyNode.erase(old->key);
                delete old;
                currSize--;
            }
            currSize++;
            minFreq = 1;
        }
        if (!freqNode.count(node->cnt))
            freqNode[node->cnt] = new DLL();
        LFUnode* tail = freqNode[node->cnt]->tail;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
        // key -> node
        keyNode[key] = node;
    }
};
