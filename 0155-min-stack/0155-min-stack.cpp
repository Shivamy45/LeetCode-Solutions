class MinStack {
public:
    stack<pair<long long, long long>> st;
    long long minVal = LLONG_MAX;
    MinStack() {}

    void push(int val) {
        if (val < minVal)
            minVal = val;
        st.push({val, minVal});
    }
    void pop() {
        st.pop();
        if (st.empty())
            minVal = LLONG_MAX;
        else 
            minVal = getMin();
    }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};