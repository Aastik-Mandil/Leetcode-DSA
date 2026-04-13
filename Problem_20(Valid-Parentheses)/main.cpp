class Solution {
    bool isOpenBracket(char ch){
        return ch=='(' || ch=='{' || ch=='[';
    }
    bool isEndingMatch(char ch1, char ch2){
        if(ch1 =='('){
            return ch2==')';
        }
        if(ch1=='{'){
            return ch2=='}';
        }
        if(ch1=='['){
            return ch2==']';
        }
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(char &ch: s){
            if(isOpenBracket(ch)){
                st.push(ch);
            }
            else{
                if(st.size() == 0 || !isEndingMatch(st.top(), ch)){
                    return false;
                }
                st.pop();
            }
        }
        return st.size()==0;
    }
};
// PROBLEM:- https://leetcode.com/problems/valid-parentheses/description/
