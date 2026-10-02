class StockSpanner {
    vector<pair<int, int>> ans;
public:
    StockSpanner() {
        ans.clear();
    }
    
    int next(int price) {
        int count = 1;
        while(ans.size() > 0 && ans.back().first<=price){
            count += ans.back().second;
            ans.pop_back();
        }
        ans.push_back({price, count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// PROBLEM:- https://leetcode.com/problems/online-stock-span/description
