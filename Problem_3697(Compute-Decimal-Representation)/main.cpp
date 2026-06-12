class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        int val = 10;
        while(n > val){
            if(n%val > 0){
                ans.insert(ans.begin(), n%val);
            }
            n -= (n%val);
            val *= 10;
        }
        if(n > 0){
            ans.insert(ans.begin(), n);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/compute-decimal-representation/description/
