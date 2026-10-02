class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, set<int>> mp;
        int n = responses.size();
        for(int i=0; i<n; i++){
            for(string &res: responses[i]){
                mp[res].insert(i);
            }
        }
        int cnt = 0;
        string ans = "";
        for(auto itr=mp.begin(); itr!=mp.end(); itr++){
            if(itr->second.size() == cnt){
                if(ans > itr->first){
                    ans = itr->first;
                }
            }
            else if(itr->second.size() > cnt){
                cnt = itr->second.size();
                ans = itr->first;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-the-most-common-response/description/
