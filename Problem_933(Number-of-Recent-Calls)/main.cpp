class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        while(q.size() > 0 && q.front() < (t-3000)){
            q.pop();
        }
        q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// PROBLEM:- https://leetcode.com/problems/number-of-recent-calls/description
