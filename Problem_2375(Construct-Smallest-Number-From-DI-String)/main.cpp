class Solution {
public:
    string smallestNumber(string pattern) {
        vector<pair<int, char>> v;
        int n = pattern.size();
        int count = 1;
        for(int i=1; i<n; i++){
            if(pattern[i] == pattern[i-1]){
                count++;
            }
            else{
                v.push_back({count, pattern[i-1]});
                count = 1;
            }
        }
        v.push_back({count, pattern[n-1]});

        string ans = "";
        for(int i=1; i<=(n+1); i++){
            ans.push_back(i+'0');
        }

        int total = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i].second == 'D'){
                reverse(ans.begin()+total, ans.begin()+total+v[i].first+1);
            }
            total += v[i].first;
        }

        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/construct-smallest-number-from-di-string/description/
