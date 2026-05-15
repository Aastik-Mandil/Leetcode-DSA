class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int ans = 0;
        for(char &ch: s){
            if(ch == '('){
                count++;
            }
            else{
                count--;
            }
            if(count < 0){
                ans++;
                count = 0;
            }
        }
        return ans+count;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
