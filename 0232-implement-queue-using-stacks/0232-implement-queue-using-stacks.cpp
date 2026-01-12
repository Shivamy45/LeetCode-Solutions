class MyQueue {
public:
    stack<int> s1;
    MyQueue() {}

    void push(int x) {
        if (s1.empty()) {
            s1.push(x);
            return;
        }
        int popped = pop();
        push(x);
        s1.push(popped);
    }

    int pop() {
        int popped = s1.top();
        s1.pop();
        return popped;
    }

    int peek() { return s1.top(); }

    bool empty() { return s1.empty(); }
};