class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() == k)
        return "0";
    stack<char> st;
    for (char &c : num)
    {
        while (k > 0 && !st.empty() && st.top() > c)
        {
            st.pop();
            k--;
        }
        st.push(c);
    }
    while (k > 0 && !st.empty())
    {
        st.pop();
        k--;
    }
    string res;
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    reverse(res.begin(), res.end());

    int i = 0;
    while (i < res.size() && res[i] == '0')
        i++;
    res = res.substr(i);

    return res.empty() ? "0" : res;
    }
};