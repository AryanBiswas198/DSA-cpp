class MedianFinder {
public:
    priority_queue<int> leftMax;
    priority_queue<int, vector<int>, greater<int>> rightMin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMax.empty() || num < leftMax.top()) {
            leftMax.push(num);
        }
        else{
            rightMin.push(num);
        }

        if(abs((int)leftMax.size() - (int)rightMin.size()) > 1) {
            rightMin.push(leftMax.top());
            leftMax.pop();
        }

        if(rightMin.size() > leftMax.size()) {
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }
    
    double findMedian() {
        if(leftMax.size() == rightMin.size()) {
            return (leftMax.top() + rightMin.top())/2.0;
        }
        else{
            return leftMax.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */