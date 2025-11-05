class Node {
public:
    string url;
    Node* back;
    Node* next;

    Node(string _url) {
        url = _url;
        back = nullptr;
        next = nullptr;
    }
};

class BrowserHistory {
    Node* current;

public:
    BrowserHistory(string homepage) { current = new Node(homepage); }

    void visit(string url) {
        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->back = current;
        current = newNode;
    }

    string back(int steps) {
        while (current->back && steps--) {
            current = current->back;
        }
        return current->url;
    }

    string forward(int steps) {
        while (current->next && steps--) {
            current = current->next;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */