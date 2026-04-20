class Solution {
    void reverse(vector<int> &digits){
        int i = 0, j = digits.size()-1;
        while(i<j){
            swap(digits[i], digits[j]);
            i++;
            j--;
        }
    }
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits);

        int carry = 1;
        for(int i=0; i<digits.size(); i++){
            int val = digits[i]+carry;
            digits[i] = val%10;
            carry = val/10;
        }
        while(carry>0){
            digits.push_back(carry%10);
            carry /= 10;
        }

        reverse(digits);
        return digits;
    }
};
// PROBLEM:- https://leetcode.com/problems/plus-one/description
