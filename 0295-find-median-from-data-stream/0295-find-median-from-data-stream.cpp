class MedianFinder {
private:
    priority_queue<int> smallerHalf;
    priority_queue<int, vector<int>, greater<int>> greaterHalf;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (smallerHalf.empty() || num <= smallerHalf.top())
            smallerHalf.push(num);
        else
            greaterHalf.push(num);

        if (smallerHalf.size() > greaterHalf.size() + 1) {
            greaterHalf.push(smallerHalf.top());
            smallerHalf.pop();
        } else if (greaterHalf.size() > smallerHalf.size()) {
            smallerHalf.push(greaterHalf.top());
            greaterHalf.pop();
        }
    }

    double findMedian() {
        if (smallerHalf.size() == greaterHalf.size())
            return (smallerHalf.top() + greaterHalf.top()) / 2.0;
        return smallerHalf.top();
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */