class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> minQ;
    priority_queue<int, vector<int>, less<int>   > maxQ;
    int minSize, maxSize;
    
    MedianFinder() {
        minSize = maxSize = 0; 
    }
    
    void addNum(int num) {
        if (minSize == 0) {
            minQ.push(num);
            ++ minSize;
        } else {
            if (num > minQ.top()) { // push num to minQ
                if (minSize <= maxSize) {
                    //minQ.push(num);
                    ++ minSize;
                    /// then minSize == maxSize or minSize == maxSize + 1
                } else {
                    maxQ.push(minQ.top());
                    ++ maxSize;
                    minQ.pop();
                    //minQ.push(num);
                    /// then minSize == maxSize
                }    
                minQ.push(num);
            } else if (num < maxQ.top()) { // num <= minQ -> push num to maxQ
                if (maxSize <= minSize) {
                    //maxQ.push(num); 
                    ++ maxSize;
                    /// then minSize == maxSize or minSize + 1 == maxSize
                } else {
                    minQ.push(maxQ.top());
                    ++ minSize;
                    maxQ.pop();
                    //maxQ.push(num);
                    /// then minSize == maxSize
                }
                maxQ.push(num);
            } else {
                
            }
        }    
    }
    
    double findMedian() {
        if (minSize == maxSize) {
            return 1.0 * (minQ.top() + maxQ.top()) / 2;
        } else if (minSize > maxSize) {
            return minQ.top(); 
        } else {
            return maxQ.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
