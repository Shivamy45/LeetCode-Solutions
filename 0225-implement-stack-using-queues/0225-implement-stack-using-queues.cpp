
class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {}

    void push(int x) {
        if (q2.empty())
            q1.push(x);
        else
            q2.push(x);
    }

    int pop() {
        int x = -1;
        if (q1.empty()) {
            while (!q2.empty()) {
                x = q2.front();
                q2.pop();
                if (q2.empty())
                    break;
                q1.push(x);
            }
        } else {
            while (!q1.empty()) {
                x = q1.front();
                q1.pop();
                if (q1.empty())
                    break;
                q2.push(x);
            }
        }
        return x;
    }

    int top() { return (q2.empty()) ? q1.back() : q2.back(); }

    bool empty() { return q1.empty() && q2.empty(); }
};