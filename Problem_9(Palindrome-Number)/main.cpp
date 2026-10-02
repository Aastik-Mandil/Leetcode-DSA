class Solution {
public:
    bool isPalindrome(int x) {
        string t = to_string(x);
        int i = 0, j = t.size()-1;
        while(i<j){
            if(t[i] != t[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
// PROBLEM:- https://leetcode.com/problems/palindrome-number/description
