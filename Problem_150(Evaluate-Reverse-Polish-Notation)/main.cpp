class Solution {
    bool isOperator(string s){
        vector<string> ops = {"+", "-", "/", "*"};
        return find(ops.begin(), ops.end(), s) != ops.end();
    }
    int getResult(int a, int b, string operation){
        if (operation == "+") return a + b;
        if (operation == "-") return a - b;
        if (operation == "*") return a * b;
        if (operation == "/") return a / b;
        return -1;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &token: tokens){
            if(isOperator(token)){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(getResult(a, b, token));
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
// PROBLEM:- https://leetcode.com/problems/evaluate-reverse-polish-notation/description
