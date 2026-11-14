class Solution {
    void makeTime(string &time, string &ans, int idx, char val){
        if(time[idx] == '?'){
            ans.push_back(val);
        }
        else{
            ans.push_back(time[idx]);
        }
    }
public:
    string maximumTime(string time) {
        string ans = "";
        makeTime(time, ans, 0, time[1]-'0' >= 4 && time[1]-'0' <= 9 ? '1' : '2');
        makeTime(time, ans, 1, ans[0] == '2' ? '3' : '9');
        makeTime(time, ans, 2, ':');
        makeTime(time, ans, 3, '5');
        makeTime(time, ans, 4, '9');
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/description/
