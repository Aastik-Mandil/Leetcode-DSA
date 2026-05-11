class CustomStack {
    vector<int> v;
    int limit;
public:
    CustomStack(int maxSize) {
        v.clear();
        limit = maxSize;
    }
    
    void push(int x) {
        if(v.size() == limit){
            return;
        }
        v.push_back(x);
    }
    
    int pop() {
        if(v.size() == 0){
            return -1;
        }
        int val = v.back();
        v.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<k && i<v.size(); i++){
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// PROBLEM:- https://leetcode.com/problems/design-a-stack-with-increment-operation/description/
