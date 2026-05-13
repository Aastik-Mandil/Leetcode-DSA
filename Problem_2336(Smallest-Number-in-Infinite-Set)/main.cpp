class SmallestInfiniteSet {
    set<int> st;
    int curr;
public:
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        if(st.empty()){
            return curr++;
        }
        auto itr = st.begin();
        int val = *itr;
        st.erase(itr);
        return val;
    }
    
    void addBack(int num) {
        if(num < curr){
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// PROBLEM:- https://leetcode.com/problems/smallest-number-in-infinite-set/description
