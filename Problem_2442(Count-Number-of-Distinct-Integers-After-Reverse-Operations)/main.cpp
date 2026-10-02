class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> st;
        for(int &num: nums){
            st.insert(num);
            int total = 0;
            while(num > 0){
                total = (10 * total) + (num % 10);
                num /= 10;
            }
            st.insert(total);
        }
        return st.size();
    }
};
// PROBLEM:- https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/description/
