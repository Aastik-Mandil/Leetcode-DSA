class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> big; // {smallest on top}
    priority_queue<int, vector<int>> small; // {biggest on top}
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(small.size() > 0 && small.top() > num){
            small.push(num);
        }
        else{
            big.push(num);
        }
        int diff = big.size() - small.size();
        int bigSize = big.size();
        int smallSize = small.size();
        if(diff > 1){
            while(big.size() > 0 && (bigSize - smallSize) > 1){
                small.push(big.top());
                big.pop();
                bigSize--;
                smallSize++;
            }
        }
        else if(diff < -1){
            while(small.size() > 0 && (bigSize - smallSize) < -1){
                big.push(small.top());
                small.pop();
                bigSize++;
                smallSize--;
            }
        }
    }
    
    double findMedian() {
        int size = big.size() + small.size();
        if(size%2 == 0){
            return ((big.top() + small.top()) * 1.0) / 2;
        }
        if(small.size() > big.size()){
            return small.top() * 1.0;
        }
        return big.top() * 1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// PROBLEM:- https://leetcode.com/problems/find-median-from-data-stream/description
