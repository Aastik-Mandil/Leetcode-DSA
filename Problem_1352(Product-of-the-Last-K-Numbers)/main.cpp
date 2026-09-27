class ProductOfNumbers {
    vector<int> v;
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        int ans = 1;
        for(int i=0; i<k; i++){
            ans *= v[v.size()-1-i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// PROBLEM:- https://leetcode.com/problems/product-of-the-last-k-numbers/description/
