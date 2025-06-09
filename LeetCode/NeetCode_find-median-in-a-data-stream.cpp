// https://neetcode.io/problems/find-median-in-a-data-stream?list=blind75

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, std::greater<int>> minHeap;
public:
    MedianFinder(): minHeap() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        int s = (maxHeap.size() +  minHeap.size());
        while(minHeap.size() < (s/2))
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(!minHeap.empty() && minHeap.top() < maxHeap.top())
        {
            int tmp = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(tmp);
        }
    }

    
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
        {
            return ((double)(maxHeap.top() + minHeap.top())) / 2;
        }

        return maxHeap.top();
    }
};
