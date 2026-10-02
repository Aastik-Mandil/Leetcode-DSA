class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0, j = 0;
        while(i<pushed.size() && j<popped.size()){
            if(s.size() > 0 && s.top() == popped[j]){
                j++;
                s.pop();
            }
            else{
                s.push(pushed[i++]);
            }
        }
        while(j<popped.size() && s.size() > 0 && s.top()==popped[j]){
            j++;
            s.pop();
        }
        return s.size() == 0 && j == popped.size() && i == pushed.size();
    }
};
// PROBLEM:- https://leetcode.com/problems/validate-stack-sequences/description/
