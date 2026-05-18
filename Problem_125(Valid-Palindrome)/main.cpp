class Solution {
    bool isSame(char a, char b){
        char x = (a>='A' && a<='Z') ? a+32 : a;
        char y = (b>='A' && b<='Z') ? b+32 : b;
        return x == y;
    }
    bool isChar(char ch){
        return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9');
    }
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            while(i<j && !isChar(s[i])){
                i++;
            }
            while(i<j && !isChar(s[j])){
                j--;
            }
            if(!isSame(s[i], s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
// PROBLEM:- https://leetcode.com/problems/valid-palindrome/description/
