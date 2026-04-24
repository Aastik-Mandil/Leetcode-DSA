class MinStack {
    vector<int> v;
    map<int,int> mp;
public:
    MinStack() {
        v.clear();
        mp.clear();
    }
    
    void push(int val) {
        v.push_back(val);
        mp[val]++;
    }
    
    void pop() {
        int val = v.back();
        v.pop_back();
        mp[val]--;
        if(mp[val] == 0){
            mp.erase(val);
        }
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        auto itr = mp.begin();
        return itr->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// PROBLEM:- https://leetcode.com/problems/min-stack/description
