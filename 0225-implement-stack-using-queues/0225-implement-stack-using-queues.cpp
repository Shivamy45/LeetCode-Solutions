class MyStack {
public:
    queue<int> qt;
    MyStack() {}

    void push(int x) {
        int n = qt.size();
        qt.push(x);
        for (int i = 0; i < n; i++) {
            qt.push(qt.front());
            qt.pop();
        }
    }

    int pop() {
        int x = qt.front();
        qt.pop();
        return x;
    }

    int top() { return qt.front(); }

    bool empty() { return qt.empty(); }
};